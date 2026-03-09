#!/usr/bin/env bash
set -u

BIN="./PmergeMe"
TOTAL=0
PASSED=0
FAILED=0

extract_numbers_line() {
    # Keep only integers from a line to avoid coupling tests to display spacing/punctuation.
    printf '%s\n' "$1" | grep -Eo '[0-9]+' | xargs
}

fail() {
    echo "[FAIL] $1"
    FAILED=$((FAILED + 1))
}

pass() {
    PASSED=$((PASSED + 1))
}

run_valid_case()
{
    TOTAL=$((TOTAL + 1))

    local -a nums=("$@")
    local output
    output=$($BIN "${nums[@]}" 2>&1)
    local status=$?

    if [ $status -ne 0 ]; then
        fail "valid case exited non-zero: ${nums[*]} | output: $output"
        return
    fi

    local after_line
    after_line=$(printf '%s\n' "$output" | grep -E '^After[[:space:]]*:' | head -n1)

    if [ -z "$after_line" ]; then
        fail "missing After line for: ${nums[*]} | output: $output"
        return
    fi

    local actual
    actual=$(extract_numbers_line "$after_line")

    local expected
    expected=$(printf '%s\n' "${nums[@]}" | awk '{print int($1)}' | sort -n | xargs)

    if [ "$actual" != "$expected" ]; then
        fail "wrong sort for: ${nums[*]} | expected: [$expected] got: [$actual]"
        return
    fi

    pass
}

run_invalid_case() {
    TOTAL=$((TOTAL + 1))

    local -a args=("$@")
    local output
    output=$($BIN "${args[@]}" 2>&1)
    local status=$?

    if [ $status -eq 0 ]; then
        fail "invalid case exited 0: ${args[*]}"
        return
    fi

    if ! printf '%s\n' "$output" | grep -q '^Error$'; then
        fail "invalid case missing Error output: ${args[*]} | output: $output"
        return
    fi

    pass
}

echo "Building..."
make -s || {
    echo "Build failed"
    exit 1
}

echo "Running deterministic valid tests..."
run_valid_case 42
run_valid_case 2 1
run_valid_case 3 1 2
run_valid_case 5 4 3 2 1
run_valid_case 1 1 1 1 1
run_valid_case 0 2147483647 42 42 7
run_valid_case 9 0 2 9 1
run_valid_case 10 3 10 2 8
run_valid_case 2147483647 0 1 2147483646 2
run_valid_case 100 99 98 97 96 95 94 93 92 91
run_valid_case 1 3 5 7 9 2 4 6 8 10
run_valid_case 0001 0002 0010 0000 0999

echo "Running randomized valid tests (1200 cases, sizes 1..25)..."
for _ in $(seq 1 1200); do
    size=$((RANDOM % 25 + 1))
    nums=()
    for __ in $(seq 1 "$size"); do
        nums+=("$((RANDOM % 100000))")
    done
    run_valid_case "${nums[@]}"
done

echo "Running invalid-input tests..."
run_invalid_case -1
run_invalid_case 1 -2 3
run_invalid_case 12a
run_invalid_case ""
run_invalid_case 2147483648
run_invalid_case "+12"
run_invalid_case "3.14"
run_invalid_case " 42"
run_invalid_case "42 "
run_invalid_case "1 2"
run_invalid_case "--7"
run_invalid_case "999999999999999999999"

# no-argument behavior (program only)
TOTAL=$((TOTAL + 1))
output=$($BIN 2>&1)
status=$?
if [ $status -eq 0 ] || ! printf '%s\n' "$output" | grep -q '^Error$'; then
    fail "no-arg case expected Error + non-zero"
else
    pass
fi

echo ""
echo "==== Test Summary ===="
echo "Total : $TOTAL"
echo "Passed: $PASSED"
echo "Failed: $FAILED"

if [ $FAILED -ne 0 ]; then
    exit 1
fi

echo "All tests passed."
