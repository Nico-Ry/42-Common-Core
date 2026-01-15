#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>	// std::cout, std::cerr, std::endl

int	main(void)
{
	/*
		Test 1: Form constructor must reject invalid grades.
		Grade 0 is invalid (valid range is [1..150]).
	*/
	std::cout << "---Invalid Form (exec grade 0)---" << std::endl;
	try
	{
		Form	f0("InvalidExecGrade", 10, 0);
		std::cout << f0 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/*
		Test 2: Successful signing.
		- Form requires sign grade 50.
		- Bureaucrat grade 50 is allowed (<= required grade).
	*/
	std::cout << "\n---Successful signing---" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 50);
		Form		f1("PermitA", 50, 100);

		std::cout << bob << std::endl;
		std::cout << f1 << std::endl;

		bob.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	/*
		Test 3: Failed signing (bureaucrat grade too low).
		- Form requires sign grade 10.
		- Bureaucrat grade 50 is not allowed (50 > 10).
	*/
	std::cout << "\n---Failed signing (grade too low)---" << std::endl;
	try
	{
		Bureaucrat	alice("Alice", 50);
		Form		f2("TopSecret", 10, 10);

		std::cout << alice << std::endl;
		std::cout << f2 << std::endl;

		alice.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	/*
		Test 4: Signing an already-signed form should keep it signed.
		Depending on implementation, it can either:
		- do nothing, or
		- print that it was already signed
	*/
	std::cout << "\n---Signing an already-signed form---" << std::endl;
	try
	{
		Bureaucrat	juan("Juan", 1);
		Form		f3("RepeatSign", 150, 150);

		juan.signForm(f3);
		juan.signForm(f3);
		std::cout << f3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	return 0;
}
