#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

#define NOC		"\033[0m"
#define GREEN	"\033[1;32m"
#define RED		"\033[1;31m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"

static void	printTitle(const std::string &title)
{
	std::cout << BLUE << "\n===== " << title << " =====" << NOC << std::endl;
}

int	main(void)
{
	printTitle("EX03 - Intern");

	Intern		intern;
	Bureaucrat	low("LowRank", 150);
	Bureaucrat	mid("MidRank", 50);
	Bureaucrat	high("HighRank", 1);

	std::cout << YELLOW << "\n--- Bureaucrats ---" << NOC << std::endl;
	std::cout << low << std::endl;
	std::cout << mid << std::endl;
	std::cout << high << std::endl;

	printTitle("Create known forms");
	AForm	*f1 = intern.makeForm("shrubbery creation", "home");
	AForm	*f2 = intern.makeForm("robotomy request", "Bender");
	AForm	*f3 = intern.makeForm("presidential pardon", "Arthur Dent");

	printTitle("Create unknown form");
	AForm	*bad = intern.makeForm("coffee request", "me");

	if (bad == NULL)
		std::cout << RED << "NULL returned (unknown form)" << NOC << std::endl;

	printTitle("Sign + execute (expected failures/success)");
	if (f1)
	{
		std::cout << YELLOW << "\n[shrubbery]" << NOC << std::endl;
		low.signForm(*f1);
		high.signForm(*f1);
		low.executeForm(*f1);
		high.executeForm(*f1);
	}

	if (f2)
	{
		std::cout << YELLOW << "\n[robotomy]" << NOC << std::endl;
		mid.signForm(*f2);
		std::cout << BLUE << "\n[MidRank tries to execute]" << NOC << std::endl;
		mid.executeForm(*f2);
		std::cout << GREEN << "\n[HighRank executes]" << NOC << std::endl;
		high.executeForm(*f2);
	}

	if (f3)
	{
		std::cout << YELLOW << "\n[pardon]" << NOC << std::endl;
		mid.signForm(*f3);
		high.signForm(*f3);
		mid.executeForm(*f3);
		high.executeForm(*f3);
	}

	printTitle("Cleanup");
	delete f1;
	delete f2;
	delete f3;

	std::cout << GREEN << "\nDone ✓" << NOC << std::endl;
	return 0;
}
