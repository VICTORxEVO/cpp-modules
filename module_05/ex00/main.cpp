#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("Alice", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	b("Bob", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception on creation: " << e.what() << std::endl;
	}
	return (0);
}
