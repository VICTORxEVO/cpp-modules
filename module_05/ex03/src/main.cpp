#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm *rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		Bureaucrat boss("Boss", 1);
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	someRandomIntern.makeForm("not a real form", "test");

	return 0;
}
