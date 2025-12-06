#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeSign, int gradeExec)
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name),
	  _signed(other._signed),
	  _gradeSign(other._gradeSign),
	  _gradeExec(other._gradeExec)
{
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

Form::~Form(void)
{
}

const std::string	&Form::getName(void) const
{
	return (_name);
}

int	Form::getGradeSign(void) const
{
	return (_gradeSign);
}

int	Form::getGradeExec(void) const
{
	return (_gradeExec);
}

bool	Form::isSigned(void) const
{
	return (_signed);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade too high");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade too low");
}

std::ostream	&operator<<(std::ostream &o, const Form &f)
{
	o << "Form \"" << f.getName()
	  << "\", signed: " << (f.isSigned() ? "yes" : "no")
	  << ", grade to sign: " << f.getGradeSign()
	  << ", grade to execute: " << f.getGradeExec()
	  << ".";
	return (o);
}
