#include "Intern.hpp"

Intern::Intern(void) {}
Intern::Intern(const Intern &other)
{
    (void)other;
}
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}
Intern::~Intern(void) {}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) const
{
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			for (int j = 0; j < 3; j++)
				if (j != i)
					delete forms[j];
			return (forms[i]);
		}
	}

	std::cout << "Intern can't create \"" << name << "\" (unknown form)" << std::endl;

	for (int i = 0; i < 3; i++)
		delete forms[i];

	return (NULL);
}
