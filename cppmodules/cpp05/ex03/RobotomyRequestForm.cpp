#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>		// rand, srand
#include <ctime>		// time
#include <iostream>		// std::cout

/*
	Default constructor.
	Required grades (subject):
	- sign: 72
	- execute: 45
*/
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

/*
	Constructor with target.
*/
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

/*
	Copy constructor.
*/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original)
	: AForm(original), _target(original._target)
{
}

/*
	Copy assignment operator.
	The target is const and cannot be reassigned.
*/
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
	(void)original;
	return *this;
}

/*
	Destructor.
*/
RobotomyRequestForm::~RobotomyRequestForm()
{
}

/*
	Returns the target.
*/
std::string	RobotomyRequestForm::getTarget() const
{
	return _target;
}

/*
	Creates a copy of the same concrete type.
*/
AForm	*RobotomyRequestForm::clone() const
{
	return new RobotomyRequestForm(*this);
}

/*
	Creates a new instance of the same concrete type with the given target.
*/
AForm	*RobotomyRequestForm::clone(std::string target) const
{
	return new RobotomyRequestForm(target);
}

/*
	Executes the robotomy request.
	Checks enforced:
	- The form must be signed.
	- The executor must have sufficient grade.
*/
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();

	/*
		Seed the random generator once per program execution.
	*/
	static bool	seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}

	std::cout << "* drilling noises *" << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}

/*
	Optional output stream overload.
*/
std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &r)
{
	out << r.getName() << " targeting " << r.getTarget();
	return out;
}
