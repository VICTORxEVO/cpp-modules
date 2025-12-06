#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o)
	: AForm(o), _target(o._target)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &o)
{
	AForm::operator=(o);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecution(executor);

	std::ofstream file((_target + "_shrubbery").c_str());
	file << "   ccee88oo\n"
			" C8O8O8Q8PoOb o8oo\n"
			"dOB69QO8PdUOpugoO9bD\n"
			"CgggbU8OU qOp qOdoUOdcb\n"
			"    6OuU  /p u gcoUodpP\n"
			"      \\\\//  /douUP\n"
			"        \\\\////\n"
			"         |||/\\\n"
			"         |||\\/\n"
			"         |||||\n"
			"   .....//||||\\....\n";
	file.close();
}
