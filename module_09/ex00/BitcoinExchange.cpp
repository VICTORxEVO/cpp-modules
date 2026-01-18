#include "BitcoinExchange.hpp"


BitcoinExchange:: BitcoinExchange() {}

BitcoinExchange:: BitcoinExchange(const BitcoinExchange &other)
{
    _database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    if (start == std:: string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename. c_str());
    if (!file. is_open())
        return false;

    std::string line;
    std::getline(file, line); // Skip header line

    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;

        std:: string date = trim(line.substr(0, pos));
        std::string rateStr = trim(line.substr(pos + 1));

        float rate = static_cast<float>(std::atof(rateStr.c_str()));
        _database[date] = rate;
    }

    file.close();
    return true;
}

bool BitcoinExchange:: isValidDate(const std::string &date)
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    std:: string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (size_t i = 0; i < yearStr.length(); i++)
    {
        if (! std::isdigit(yearStr[i]))
            return false;
    }
    for (size_t i = 0; i < monthStr.length(); i++)
    {
        if (!std::isdigit(monthStr[i]))
            return false;
    }
    for (size_t i = 0; i < dayStr.length(); i++)
    {
        if (!std::isdigit(dayStr[i]))
            return false;
    }

    int year = std::atoi(yearStr. c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeap)
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value)
{
    if (valueStr.empty())
        return false;

    char *endPtr;
    double tempValue = std::strtod(valueStr.c_str(), &endPtr);

    if (*endPtr != '\0')
        return false;

    value = static_cast<float>(tempValue);
    return true;
}

float BitcoinExchange:: getExchangeRate(const std::string &date)
{
    std::map<std::string, float>:: iterator it = _database.lower_bound(date);

    // Exact match found
    if (it != _database.end() && it->first == date)
        return it->second;

    // No lower date exists
    if (it == _database.begin())
        return -1;

    // Step back to get closest lower date
    --it;
    return it->second;
}

void BitcoinExchange:: processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std:: cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header line

    while (std::getline(file, line))
    {
        // Check format
        size_t pos = line.find('|');
        if (pos == std:: string::npos)
        {
            std:: cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error:  too large a number." << std::endl;
            continue;
        }

        float rate = getExchangeRate(date);
        if (rate < 0)
        {
            std:: cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float result = value * rate;
        std:: cout << date << " => " << value << " = " << result << std::endl;
    }

    file.close();
}