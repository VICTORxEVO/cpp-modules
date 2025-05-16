#include "phonebook.hpp"
#include <iostream>
#include <string>

int main(void)
{
    phonebook phonebook;
    std::string command;

    phonebook.index = 0;
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "ADD")
            phonebook.add();
        else if (command == "SEARCH")
            phonebook.search();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}