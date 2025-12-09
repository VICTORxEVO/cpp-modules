#include "Span.hpp"

// Default constructor
Span::Span(void) : _maxSize(0)
{
}

// Parameterized constructor
Span::Span(unsigned int n) : _maxSize(n)
{
}

// Copy constructor
Span::Span(const Span &src) : _maxSize(src._maxSize), _numbers(src._numbers)
{
}

// Assignment operator
Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_maxSize = rhs._maxSize;
		this->_numbers = rhs._numbers;
	}
	return (*this);
}

// Destructor
Span::~Span(void)
{
}

// Add a single number
void	Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_maxSize)
		throw std::runtime_error("Span is full: cannot add more numbers");
	this->_numbers.push_back(number);
}

// Find shortest span (smallest difference between any two numbers)
int	Span::shortestSpan(void) const
{
	if (this->_numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers to find span");

	// Create a sorted copy
	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());

	// Find minimum difference between adjacent elements
	int	minSpan = INT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

// Find longest span (difference between max and min)
int	Span::longestSpan(void) const
{
	if (this->_numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers to find span");

	int minVal = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int maxVal = *std::max_element(this->_numbers.begin(), this->_numbers.end());

	return (maxVal - minVal);
}

// Getters
unsigned int	Span::getMaxSize(void) const
{
	return (this->_maxSize);
}

const std::vector<int>&	Span::getNumbers(void) const
{
	return (this->_numbers);
}