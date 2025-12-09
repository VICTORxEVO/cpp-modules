#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << "\n========== PRESIDENTIAL PARDON FORM TESTS ==========" << std::endl;

	try
	{
		std::cout << "\n--- Creating PresidentialPardonForm ---" << std::endl;
		PresidentialPardonForm ppf("John Doe");
		std::cout << ppf << std::endl;

		std::cout << "\n--- Bureaucrat trying to sign (grade too low) ---" << std::endl;
		Bureaucrat	bob("Bob", 100);
		std::cout << bob << std::endl;
		bob.signForm(ppf);

		std::cout << "\n--- Valid Bureaucrat signing form ---" << std::endl;
		Bureaucrat	presidentOfBureau("President", 1);
		std::cout << presidentOfBureau << std::endl;
		presidentOfBureau.signForm(ppf);

		std::cout << "\n--- Executing signed form ---" << std::endl;
		presidentOfBureau.executeForm(ppf);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== ROBOTOMY REQUEST FORM TESTS ==========" << std::endl;

	try
	{
		std::cout << "\n--- Creating RobotomyRequestForm ---" << std::endl;
		RobotomyRequestForm rrf("Bender");
		std::cout << rrf << std::endl;

		std::cout << "\n--- Signing and executing RobotomyRequestForm ---" << std::endl;
		Bureaucrat	techie("Techie", 45);
		std::cout << techie << std::endl;
		techie.signForm(rrf);
		techie.executeForm(rrf);

		std::cout << "\n--- Executing again (50% success chance) ---" << std::endl;
		techie.executeForm(rrf);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== SHRUBBERY CREATION FORM TESTS ==========" << std::endl;

	try
	{
		std::cout << "\n--- Creating ShrubberyCreationForm ---" << std::endl;
		ShrubberyCreationForm scf("Home");
		std::cout << scf << std::endl;

		std::cout << "\n--- Signing and executing ShrubberyCreationForm ---" << std::endl;
		Bureaucrat	gardener("Gardener", 100);
		std::cout << gardener << std::endl;
		gardener.signForm(scf);
		gardener.executeForm(scf);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== EDGE CASE TESTS ==========" << std::endl;

	try
	{
		std::cout << "\n--- Executing unsigned form ---" << std::endl;
		PresidentialPardonForm unsignedForm("Criminal");
		Bureaucrat	executor("Executor", 1);
		executor.executeForm(unsignedForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught FormNotSignedException: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Executing with insufficient grade ---" << std::endl;
		PresidentialPardonForm ppf2("Criminal2");
		Bureaucrat	weakBureau("WeakBureau", 100);
		weakBureau.signForm(ppf2);
		weakBureau.executeForm(ppf2);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
	}

	return (0);
}
