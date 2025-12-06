#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
	public:
		Form(const std::string &name, int gradeSign, int gradeExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		const std::string	&getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				isSigned(void) const;

		void				beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
};

std::ostream	&operator<<(std::ostream &o, const Form &f);

#endif
