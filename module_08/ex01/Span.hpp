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

		Span(void);
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span(void);

		void	addNumber(int number);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
        
		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end);

		unsigned int				getMaxSize(void) const;
		const std::vector<int>&		getNumbers(void) const;
};

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