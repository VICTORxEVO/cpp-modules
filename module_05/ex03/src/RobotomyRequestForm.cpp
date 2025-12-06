#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequest", 72, 45), _target(target)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o)
	: AForm(o), _target(o._target)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &o)
{
	AForm::operator=(o);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExecution(executor);

	std::cout << "Bzzzzzzzz... drilling noises...\n";

	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << std::endl;
}
