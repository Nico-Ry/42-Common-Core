#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

/*
	RobotomyRequestForm:
	- Concrete form derived from AForm.
	- Stores a target.
	- On execute(), performs a robotomy attempt with a 50% success rate.
*/
class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;

	public:
		/* Orthodox Canonical Form */
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &original);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &original);
		~RobotomyRequestForm();

		/* Target accessor */
		std::string	getTarget() const;

		/* AForm interface */
		void	execute(Bureaucrat const &executor) const;
		AForm	*clone() const;
		AForm	*clone(std::string target) const;
};

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &r);

#endif
