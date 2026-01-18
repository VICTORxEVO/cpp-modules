#include "RPN.hpp"


Rpn::Rpn() : _stack()
{

}

Rpn::Rpn(const std::string &s)
{
    compute(s);
}
Rpn::Rpn(const Rpn &other) : _stack(other._stack)
{

}

Rpn &Rpn::operator=(const Rpn &other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return (*this);
}

Rpn::~Rpn()
{

}

std::vector<std::string> Rpn::tokinize(const std::string &input)
{
    std::stringstream ss(input);
    std::vector<std::string> tokens;
    std::string token;

    while (ss >> token)
        tokens.push_back(token);
    return (tokens);
}

void    Rpn::compute(const std::string &s)
{
    std::vector<std::string> tokens;
    intmax_t val1, val2;

    tokens = tokinize(s);
    for (std::size_t i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].size() == 1)
        {
            if (tokens[i][0] >= '0' && tokens[i][0] <= '9')
                _stack.push(tokens[i][0] - '0');
            else if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/')
            {
                if (_stack.empty() || _stack.size() == 1)
                {
                    _stack.push(0);
                    return ;
                }
                val2 = _stack.top(); _stack.pop();
                val1 = _stack.top(); _stack.pop();
                if (tokens[i][0] == '+')
                    _stack.push(val1 + val2);
                else if (tokens[i][0] == '-')
                    _stack.push(val1 - val2);
                else if (tokens[i][0] == '*')
                    _stack.push(val1 * val2);
                else if (tokens[i][0] == '/')
                {
                    if (val1 != 0)
                        _stack.push(val1 / val2);
                    else
                        throw std::runtime_error("Error: devition by 0");
                }
                else
                    throw std::runtime_error("Error");
            }
        }
        else
            throw std::runtime_error("Error");
    }

}

intmax_t Rpn::getRes(void) const
{
    return (_stack.top());
}

std::ostream &operator<<(std::ostream &os, const Rpn &other)
{
    os << other.getRes();
    return (os);
}