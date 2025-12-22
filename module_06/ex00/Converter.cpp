#include "Converter.hpp"

static bool isChar(const std::string &s)
{
	if (s.length() == 1 && !isdigit(s[0]))
		return (true);
	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
		return (true);
	return (false);
}

static bool isInt(const std::string &s)
{
	int i = 0;

	if (s[i] == '-' || s[i] == '+')
		i++;
	if (i == static_cast<int>(s.length()))
		return false;
	for (; i < static_cast<int>(s.length()); i++)
	{
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}

static bool isFloat(const std::string &s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return true;

	if (s[s.length() - 1] != 'f')
		return false;

	bool dot = false;
	int i = 0;

	if (s[i] == '-' || s[i] == '+')
		i++;
	for (; i < (int)s.length() - 1; i++)
	{
		if (s[i] == '.')
		{
			if (dot)
				return false;
			dot = true;
		}
		else if (!isdigit(s[i]))
			return false;
	}
	return dot;
}

static bool isDouble(const std::string &s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return true;

	bool dot = false;
	int i = 0;

	if (s[i] == '-' || s[i] == '+')
		i++;
	for (; i < (int)s.length(); i++)
	{
		if (s[i] == '.')
		{
			if (dot)
				return false;
			dot = true;
		}
		else if (!isdigit(s[i]))
			return false;
	}
	return dot;
}

static void printChar(double v)
{
	if (std::isnan(v) || std::isinf(v) || v < 0 || v > 127)
		std::cout << "char: impossible" << std::endl;
	else if (v < 32 || v > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(v) << "'" << std::endl;
}

static void printInt(double v)
{
	if (v < std::numeric_limits<int>::min() ||
		v > std::numeric_limits<int>::max() ||
		std::isnan(v) || std::isinf(v))
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
		std::cout << "int: " << static_cast<int>(v) << std::endl;
}

static void printFloat(double v)
{
	std::cout << "float: ";
	if (std::isnan(v))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(v))
		std::cout << (v < 0 ? "-inff" : "+inff") << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1)
		          << static_cast<float>(v) << "f" << std::endl;
	}
}

static void printDouble(double v)
{
	std::cout << "double: ";
	if (std::isnan(v))
		std::cout << "nan" << std::endl;
	else if (std::isinf(v))
		std::cout << (v < 0 ? "-inf" : "+inf") << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1)
		          << v << std::endl;
	}
}

static double toDouble(const std::string &s)
{
	return (std::strtod(s.c_str(), NULL));
}


void Converter::convert(const std::string &s)
{
	double value = 0.0;

	if (isChar(s))
	{
		if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
			value = static_cast<double>(s[1]);
		else
			value = static_cast<double>(s[0]);
	}
	else if (isInt(s))
		value = static_cast<double>(std::atoi(s.c_str()));
	else if (isFloat(s))
		value = toDouble(s);
	else if (isDouble(s))
		value = toDouble(s);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

Converter::Converter()
{
}

Converter::~Converter()
{
}

Converter::Converter(const Converter &other)
{
	(void)other;
}

Converter &Converter::operator=(const Converter &other)
{
	(void)other;
	return (*this);
}
