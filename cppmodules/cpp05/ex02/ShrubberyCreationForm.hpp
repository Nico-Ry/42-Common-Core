#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <exception>	// std::exception

/*
	ShrubberyCreationForm:
	- Concrete form derived from AForm.
	- Stores a target used to create the output file "<target>_shrubbery".
*/
class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;

	public:
		/* Orthodox Canonical Form */
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &original);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &original);
		~ShrubberyCreationForm();

		/* Accessor for the target */
		std::string	getTarget() const;

		/*
			Executes the form behavior.
			Expected checks (enforced before doing the action):
			- form must be signed
			- executor must have sufficient grade
		*/
		void	execute(Bureaucrat const &executor) const;

		/*
			Thrown when the output file cannot be opened/created.
		*/
		class FileOpenException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

/*
	Optional output stream overload for this concrete form.
*/
std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &s);

#endif
