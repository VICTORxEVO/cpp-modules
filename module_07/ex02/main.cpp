#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

template <typename T>
void printArray(Array<T> const &arr, std::string const &name)
{
    std::cout << name << " (size " << arr.size() << "): ";
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}



int main(void)
{
    std::cout << "===== BASIC TESTS =====" << std::endl;

    // Test empty array
    std::cout << "\n--- Empty Array ---" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    // Test array with size
    std::cout << "\n--- Array with size ---" << std::endl;
    Array<int> numbers(5);
    std::cout << "Default values: ";
    printArray(numbers, "numbers");

    // Modify values
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = (i + 1) * 10;
    printArray(numbers, "numbers");

    // Test copy constructor
    std::cout << "\n--- Copy Constructor ---" << std::endl;
    Array<int> copy(numbers);
    printArray(copy, "copy");

    // Modify original - copy should NOT change
    numbers[0] = 999;
    std::cout << "After modifying original:" << std::endl;
    printArray(numbers, "numbers");
    printArray(copy, "copy");

    // Test assignment operator
    std::cout << "\n--- Assignment Operator ---" << std::endl;
    Array<int> assigned;
    assigned = numbers;
    printArray(assigned, "assigned");

    // Modify assigned - original should NOT change
    assigned[1] = 888;
    std::cout << "After modifying assigned:" << std::endl;
    printArray(numbers, "numbers");
    printArray(assigned, "assigned");

    // Test with different types
    std::cout << "\n===== DIFFERENT TYPES =====" << std::endl;

    // Float array
    std::cout << "\n--- Float Array ---" << std::endl;
    Array<float> floats(3);
    floats[0] = 1.1f;
    floats[1] = 2.2f;
    floats[2] = 3.3f;
    printArray(floats, "floats");

    // String array
    std::cout << "\n--- String Array ---" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "42";
    strings[2] = "World";
    printArray(strings, "strings");

    // Test out of bounds exception
    std::cout << "\n===== EXCEPTION TESTS =====" << std::endl;
    try
    {
        std::cout << "Trying to access index 100..." << std::endl;
        std::cout << numbers[100] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to access empty array..." << std::endl;
        std::cout << empty[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Subject's complex test
    std::cout << "\n===== SUBJECT TEST =====" << std::endl;
    Array<int> numbers2(MAX_VAL);
    int *mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        int const value = rand();
        numbers2[i] = value;
        mirror[i] = value;
    }

    delete[] mirror;

    return 0;
}