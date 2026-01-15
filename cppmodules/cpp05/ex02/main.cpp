#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/*
	Colors for readable output in the terminal.
*/
#define NOC		"\033[0m"
#define GREEN	"\033[1;32m"
#define RED		"\033[1;31m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"

int	main(void)
{
	std::cout << BLUE << "\n===== EX02 TESTS =====\n" << NOC << std::endl;

	/*
		Create bureaucrats with different authority levels.
	*/
	Bureaucrat	low("LowRank", 150);
	Bureaucrat	mid("MidRank", 50);
	Bureaucrat	high("HighRank", 1);

	std::cout << YELLOW << "--- Bureaucrats ---" << NOC << std::endl;
	std::cout << low << std::endl;
	std::cout << mid << std::endl;
	std::cout << high << std::endl;

	/*
		Create forms.
	*/
	ShrubberyCreationForm	shrub("home");
	RobotomyRequestForm		robot("Bender");
	PresidentialPardonForm	pardon("Arthur Dent");

	std::cout << YELLOW << "\n--- Forms created ---" << NOC << std::endl;
	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	/*
		Test 1: Execute without signing (must fail).
	*/
	std::cout << YELLOW << "\n--- Execute unsigned forms ---" << NOC << std::endl;
	high.executeForm(shrub);
	high.executeForm(robot);
	high.executeForm(pardon);

	/*
		Test 2: Signing forms with insufficient and sufficient grades.
	*/
	std::cout << YELLOW << "\n--- Signing forms ---" << NOC << std::endl;
	low.signForm(shrub);		// should fail
	mid.signForm(shrub);		// should succeed

	mid.signForm(robot);		// should succeed
	mid.signForm(pardon);		// should fail
	high.signForm(pardon);		// should succeed

	/*
		Test 3: Execute forms with different bureaucrats.
	*/
	std::cout << YELLOW << "\n--- Executing forms ---" << NOC << std::endl;

	std::cout << GREEN << "\n[HighRank executes all]" << NOC << std::endl;
	high.executeForm(shrub);
	high.executeForm(robot);
	high.executeForm(pardon);

	std::cout << RED << "\n[MidRank tries to execute presidential pardon]" << NOC << std::endl;
	mid.executeForm(pardon);

	std::cout << BLUE << "\n===== END OF TESTS =====\n" << NOC << std::endl;

	return 0;
}
