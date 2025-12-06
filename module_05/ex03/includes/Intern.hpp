#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern(void);

		AForm	*makeForm(const std::string &name, const std::string &target) const;
};

#endif
