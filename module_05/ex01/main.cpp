#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("Alice", 50);
		Form		f("Contract", 40, 20);
		Form		f2("Covenant", 100, 50);

		std::cout << a << std::endl;
		std::cout << f << std::endl;
		std::cout << f2 << std::endl;

		a.signForm(f); //  fail (50 > 40)
		a.signForm(f2);// succeed (50 < 100)

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
