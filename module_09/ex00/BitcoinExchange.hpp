#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <vector>
# include <cstdlib>

class BitcoinExchange
{
private:
    std:: map<std::string, float> _database;

    bool isValidDate(const std::string &date);
    bool isValidValue(const std::string &valueStr, float &value);
    float getExchangeRate(const std::string &date);
    std::string trim(const std::string &str);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string &filename);
    void processInput(const std::string &filename);
};

#endif
