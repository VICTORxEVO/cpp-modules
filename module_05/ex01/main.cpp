#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("Alice", 50);
		Form		f("Contract", 40, 20);

		std::cout << a << std::endl;
		std::cout << f << std::endl;

		a.signForm(f); //  fail (50 > 40)

		Bureaucrat	b("Boss", 1);
		b.signForm(f); //  succeed

		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
