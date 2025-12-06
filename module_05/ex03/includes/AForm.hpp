#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string &name, int gradeSign, int gradeExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm(void);

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;

		void				beSigned(const Bureaucrat &b);


		virtual void		execute(Bureaucrat const &executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	protected:
		void	checkExecution(Bureaucrat const &executor) const;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
};

std::ostream	&operator<<(std::ostream &o, const AForm &f);

#endif

