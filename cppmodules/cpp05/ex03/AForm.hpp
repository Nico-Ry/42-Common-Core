#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>		// std::string
#include <exception>	// std::exception
#include <ostream>		// std::ostream

class Bureaucrat;

/*
	AForm:
	- Base class for all forms.
	- Stores common state (name, signed flag, required grades).
	- beSigned() enforces signing permissions.
	- execute() is pure virtual (derived forms define the action).
	- clone() helpers are used by Intern to create new instances.
*/
class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		/* Orthodox Canonical Form */
		AForm();
		AForm(std::string name);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &original);
		AForm&	operator=(const AForm &original);
		virtual ~AForm();

		/* Getters */
		const std::string	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		/*
			Sets the form to signed if the bureaucrat grade is sufficient.
			Throws GradeTooLowException otherwise.
		*/
		void				beSigned(const Bureaucrat &bureaucrat);

		/*
			Derived forms implement their execution behavior.
			Checks expected before performing the action:
			- form must be signed
			- executor must have sufficient grade
		*/
		virtual void		execute(Bureaucrat const &executor) const = 0;

		/*
			Clone helpers used by Intern.
			- clone() creates a copy of the same concrete type.
			- clone(target) creates a new instance of the same type with a target.
		*/
		virtual AForm		*clone() const = 0;
		virtual AForm		*clone(std::string target) const = 0;

		/* Exceptions */
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &f);

#endif
