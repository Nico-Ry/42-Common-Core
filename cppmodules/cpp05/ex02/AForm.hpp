#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>		// std::string
#include <exception>	// std::exception
#include <ostream>		// std::ostream

class Bureaucrat;

/*
	AForm:
	- Abstract base class for all forms.
	- Stores common state (name, signed flag, required grades).
	- Enforces signing rules via beSigned().
	- Declares execute() as a pure virtual function (must be implemented by derived forms).
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
			Attempts to sign the form with the given bureaucrat.
			Throws GradeTooLowException if the bureaucrat grade is insufficient.
		*/
		void				beSigned(const Bureaucrat &bureaucrat);

		/*
			Execution interface:
			- Derived forms must implement their execution behavior.
			- Derived forms must enforce:
				- form must be signed
				- executor must have sufficient grade
		*/
		virtual void		execute(Bureaucrat const &executor) const = 0;

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

/* Output stream overload for AForm */
std::ostream	&operator<<(std::ostream &out, const AForm &f);

#endif
