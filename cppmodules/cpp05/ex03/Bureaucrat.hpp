#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>		// std::string
#include <exception>	// std::exception
#include <ostream>		// std::ostream

class AForm;

/*
	Bureaucrat:
	- Has a constant name.
	- Has a grade in the range [1, 150].
	- Can attempt to sign and execute forms.
*/
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		/* Orthodox Canonical Form */
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		/* Getters */
		const std::string	getName() const;
		int					getGrade() const;

		/* Grade modification */
		void	incrementGrade();
		void	decrementGrade();

		/*
			Attempts to sign a form.
			Prints the result of the operation.
		*/
		void	signForm(AForm &form) const;

		/*
			Attempts to execute a form.
			Prints the result of the operation.
		*/
		void	executeForm(AForm const &form) const;

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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
