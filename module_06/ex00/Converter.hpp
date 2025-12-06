#pragma once

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <cmath>

class Converter
{
    public:
        static void convert(const std::string &s);
    private:
        Converter();
        ~Converter();
        Converter(const Converter &other);
        Converter &operator=(const Converter &other);
};