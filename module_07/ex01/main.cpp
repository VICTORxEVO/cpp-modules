#include <iostream>
#include <string>
#include "iter.hpp"

// Print element (const version - read only)
template <typename T>
void print(T const &elem)
{
    std::cout << elem << " ";
}

// Double the value (non-const - modifies element)
template <typename T>
void doubleValue(T &elem)
{
    elem *= 2;
}

// Increment value
template <typename T>
void increment(T &elem)
{
    elem += 1;
}

// To uppercase (for strings)
void toUpper(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

int main(void)
{
    std::cout << "===== TEST WITH INT ARRAY =====" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;

    iter(intArray, intSize, doubleValue<int>);
    std::cout << "After double: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;

    iter(intArray, intSize, increment<int>);
    std::cout << "After increment: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "===== TEST WITH FLOAT ARRAY =====" << std::endl;
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f};
    size_t floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    std::cout << "Original: ";
    iter(floatArray, floatSize, print<float>);
    std::cout << std::endl;

    iter(floatArray, floatSize, doubleValue<float>);
    std::cout << "After double: ";
    iter(floatArray, floatSize, print<float>);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "===== TEST WITH STRING ARRAY =====" << std::endl;
    std::string strArray[] = {"ohayo", "sekai"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original: ";
    iter(strArray, strSize, print<std::string>);
    std::cout << std::endl;

    iter(strArray, strSize, toUpper);
    std::cout << "After toUpper: ";
    iter(strArray, strSize, print<std::string>);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "===== TEST WITH CONST ARRAY =====" << std::endl;
    int const constArray[] = {10, 20, 30, 40, 50};
    size_t constSize = sizeof(constArray) / sizeof(constArray[0]);

    std::cout << "Const array: ";
    iter(constArray, constSize, print<int>);
    std::cout << std::endl;

    return (0);
}