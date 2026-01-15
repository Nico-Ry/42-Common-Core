#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>	// std::cout

/*
	Constructor.
	Initializes template instances used for cloning.
*/
Intern::Intern()
{
	_formTemplates[0] = new ShrubberyCreationForm();
	_formTemplates[1] = new RobotomyRequestForm();
	_formTemplates[2] = new PresidentialPardonForm();
}

/*
	Copy constructor.
	Creates independent template instances.
*/
Intern::Intern(const Intern &other)
{
	(void)other;
	_formTemplates[0] = new ShrubberyCreationForm();
	_formTemplates[1] = new RobotomyRequestForm();
	_formTemplates[2] = new PresidentialPardonForm();
}

/*
	Copy assignment operator.
	Rebuilds template instances.
*/
Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	delete _formTemplates[0];
	delete _formTemplates[1];
	delete _formTemplates[2];
	_formTemplates[0] = new ShrubberyCreationForm();
	_formTemplates[1] = new RobotomyRequestForm();
	_formTemplates[2] = new PresidentialPardonForm();
	return *this;
}

/*
	Destructor.
	Frees allocated template instances.
*/
Intern::~Intern()
{
	delete _formTemplates[0];
	delete _formTemplates[1];
	delete _formTemplates[2];
}

/*
	makeForm():
	- Matches the requested form name against known form names.
	- On success, prints "Intern creates <form>" and returns a new instance.
	- On failure, prints an explicit error and returns NULL.
*/
AForm	*Intern::makeForm(std::string formName, std::string target) const
{
	const std::string	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			AForm	*created = _formTemplates[i]->clone(target);
			std::cout << "Intern creates " << created->getName() << std::endl;
			return created;
		}
	}
	std::cout << "Intern cannot create form: " << formName << std::endl;
	return NULL;
}
