#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &o)
	: AForm(o), _target(o._target)
{
}

PresidentialPardonForm
&PresidentialPardonForm::operator=(const PresidentialPardonForm &o)
{
	AForm::operator=(o);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkExecution(executor);

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
	          << std::endl;
}
