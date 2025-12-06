#include "functions.hpp"

int main(void)
{
    Base *ptr = generate();

    identify(ptr);   // pointer version
    identify(*ptr);  // reference version

    delete ptr;
    return 0;
}
