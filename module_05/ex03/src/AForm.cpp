#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeSign, int gradeExec)
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name),
	  _signed(other._signed),
	  _gradeSign(other._gradeSign),
	  _gradeExec(other._gradeExec)
{
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

AForm::~AForm(void)
{
}

const std::string	&AForm::getName(void) const { return (_name); }
bool				AForm::isSigned(void) const { return (_signed); }
int					AForm::getGradeSign(void) const { return (_gradeSign); }
int					AForm::getGradeExec(void) const { return (_gradeExec); }

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void	AForm::checkExecution(Bureaucrat const &executor) const
{
	if (_signed == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeExec)
		throw AForm::GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
    return ("Form grade too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
    return ("Form grade too low");
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
    return ("Form not signed");
}

std::ostream	&operator<<(std::ostream &o, const AForm &f)
{
	o << "Form \"" << f.getName()
	  << "\", signed: " << (f.isSigned() ? "yes" : "no")
	  << ", sign grade: " << f.getGradeSign()
	  << ", exec grade: " << f.getGradeExec();
	return (o);
}
