#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int ac, char **av)
{
    std::string to_search;
    std::string to_replace;
    std::string replacement_file;
    std::string line;
    std::string tmp_line;
    size_t start, pos;

    if (ac != 4)
        return (std::cerr << "usage: <filename> <search> <replacement> !", 1);
    replacement_file = std::string(av[1]) + ".replace";
    to_search = av[2];
    to_replace = av[3];
    std::ifstream origin_file(av[1]);
    if (!origin_file.is_open())
        return (std::cerr << "error: failed to open " << av[1], 1);
    std::ofstream dest_file(replacement_file.c_str());
    if (!dest_file.is_open())
        return (std::cerr << "error: failed to open " << replacement_file, 1);
    while(std::getline(origin_file, line))
    {
        start = 0, pos = 0; // reset for new line
        tmp_line.clear(); //clear for the new line
        while ((pos = line.find(to_search, pos)) != std::string::npos)
        {
           tmp_line += line.substr(start, pos - start);
           tmp_line += to_replace;
           pos += to_search.length();
           start = pos;
        }
        tmp_line += line.substr(start);
        dest_file << tmp_line << "\n";
    }
    std::cout << "File modified successfully !" << std::endl;
    return (0);
}
