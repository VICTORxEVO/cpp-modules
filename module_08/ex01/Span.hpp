#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <climits>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		// Orthodox Canonical Form
		Span(void);
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span(void);

		// Member functions
		void	addNumber(int number);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
        
		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end);

		// Getters
		unsigned int				getMaxSize(void) const;
		const std::vector<int>&		getNumbers(void) const;
};

// Template implementation must be in header
template <typename Iterator>
void	Span::addRange(Iterator begin, Iterator end)
{
	while (begin != end)
	{
		this->addNumber(*begin);
		++begin;
	}
}

#endif