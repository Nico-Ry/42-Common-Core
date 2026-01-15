#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

/*
	PresidentialPardonForm:
	- Concrete form derived from AForm.
	- Stores a target.
	- On execute(), prints that the target has been pardoned.
*/
class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;

	public:
		/* Orthodox Canonical Form */
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &original);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &original);
		~PresidentialPardonForm();

		/* Target accessor */
		std::string	getTarget() const;

		/* AForm interface */
		void	execute(Bureaucrat const &executor) const;
		AForm	*clone() const;
		AForm	*clone(std::string target) const;
};

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &p);

#endif
