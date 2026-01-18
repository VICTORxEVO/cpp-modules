#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

class Rpn
{
    public:
        Rpn();
        Rpn(const std::string &s);
        Rpn(const Rpn &other);
        Rpn &operator=(const Rpn &other);
        ~Rpn();

        intmax_t getRes() const;
        void        compute(const std::string &s);
    private:
        std::stack<intmax_t>                 _stack;
        
        std::vector<std::string> tokinize(const std::string &input);

};

std::ostream &operator<<(std::ostream &os, const Rpn &other);