#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <exception>	// std::exception

/*
	ShrubberyCreationForm:
	- Concrete form derived from AForm.
	- Stores a target.
	- On execute(), creates "<target>_shrubbery" and writes ASCII trees.
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

		/* Target accessor */
		std::string	getTarget() const;

		/* AForm interface */
		void	execute(Bureaucrat const &executor) const;
		AForm	*clone() const;
		AForm	*clone(std::string target) const;

		/* Thrown when the output file cannot be opened/created */
		class FileOpenException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &s);

#endif
