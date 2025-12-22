#include "functions.hpp"

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    Base *ptr = generate();

    identify(ptr);   // pointer
    identify(*ptr);  // reference

    delete ptr;
    return 0;
}
