#ifndef FORM_HPP
#define FORM_HPP

#include <string>		// std::string
#include <exception>	// std::exception
#include <ostream>		// std::ostream

/*
	Forward declaration to avoid circular includes.
	The full definition is only needed in Form.cpp.
*/
class Bureaucrat;

/*
	Form:
	- Has a constant name.
	- Has a signed status (false at construction).
	- Has constant grades required to sign and to execute.
*/
class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		/* Orthodox Canonical Form */
		Form();
		Form(std::string name);
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		/* Getters */
		const std::string	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		/*
			Attempts to sign the form with the given bureaucrat.
			- If the bureaucrat grade is high enough, the form becomes signed.
			- Otherwise, throws GradeTooLowException.
		*/
		void				beSigned(const Bureaucrat &bureaucrat);

		/* Exceptions for grade bounds */
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
};

/* Output stream overload for Form */
std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
