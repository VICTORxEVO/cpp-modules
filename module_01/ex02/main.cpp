#include <iostream>
#include <string>


int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << "addr => " << &str << std::endl;
    std::cout << "addr of pointer => " << ptr << std::endl;
    std::cout << "refrence => " << &ref << std::endl;

    std::cout << "---------[VALUES]------------" << std::endl;

    std::cout << "original value => " << str << std::endl;
    std::cout << "ptr value => " << *ptr << std::endl;
    std::cout << "ref value => " << ref << std::endl;
}