#pragma once

#include <string>
#include <iostream>

class Brain
{
    public:
        std::string ideas[100];
        Brain();
        Brain(const Brain& other);
        ~Brain();
        Brain &operator=(const Brain &other);
};