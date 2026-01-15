#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>		// std::cout

/*
	Default constructor.
	Required grades (subject):
	- sign: 25
	- execute: 5
*/
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

/*
	Constructor with target.
*/
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

/*
	Copy constructor.
*/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original)
	: AForm(original), _target(original._target)
{
}

/*
	Copy assignment operator.
	The target is const and cannot be reassigned.
*/
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &original)
{
	(void)original;
	return *this;
}

/*
	Destructor.
*/
PresidentialPardonForm::~PresidentialPardonForm()
{
}

/*
	Returns the target.
*/
std::string	PresidentialPardonForm::getTarget() const
{
	return _target;
}

/*
	Executes the presidential pardon.
	Checks enforced:
	- The form must be signed.
	- The executor must have sufficient grade.
*/
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/*
	Optional output stream overload.
*/
std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &p)
{
	out << p.getName() << " targeting " << p.getTarget();
	return out;
}
