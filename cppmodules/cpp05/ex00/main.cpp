#include "Bureaucrat.hpp"
#include <iostream>	// std::cout, std::cerr, std::endl

int	main(void)
{
	/*
		Test 1: Constructor should throw when grade is out of range.
		Grade 0 is invalid (valid range is [1..150]).
	*/
	std::cout << PURPLE << "---Alberto---" << RESET << std::endl;
	try
	{
		Bureaucrat	alberto("Alberto", 0);
		(void)alberto;	// Avoid unused-variable warnings if needed
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
	}

	/*
		Test 2: Incrementing grade improves rank (number goes down).
		Starting at grade 2:
			2 -> 1 (ok)
			1 -> throws GradeTooHighException
	*/
	std::cout << PURPLE << "\n---Juan---" << RESET << std::endl;
	Bureaucrat	juan("Juan", 2);

	std::cout << juan << std::endl;
	juan.incrementGrade();
	std::cout << juan << std::endl;

	try
	{
		juan.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
	}

	/*
		Test 3: Decrementing grade worsens rank (number goes up).
		Starting at grade 149:
			149 -> 150 (ok)
			150 -> throws GradeTooLowException
	*/
	std::cout << PURPLE << "\n---Elena---" << RESET << std::endl;
	Bureaucrat	elena("Elena", 149);

	std::cout << elena << std::endl;
	elena.decrementGrade();
	std::cout << elena << std::endl;

	try
	{
		elena.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
	}

	return 0;
}
