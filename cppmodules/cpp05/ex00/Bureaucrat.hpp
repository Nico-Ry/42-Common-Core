

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>		// std::string
#include <exception>	// std::exception
#include <ostream>		// std::ostream

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define PURPLE  "\033[35m"
/*
	The Bureaucrat class represents a bureaucrat with a name and a grade.
	The grade range is strictly enforced between 1 (highest) and 150 (lowest).
*/
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		/* Constructors */
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &other);

		/* Assignment operator */
		Bureaucrat &operator=(const Bureaucrat &other);

		/* Destructor */
		~Bureaucrat();

		/* Getters */
		const std::string	getName() const;
		int					getGrade() const;

		/* Grade modification */
		void	incrementGrade();
		void	decrementGrade();

		/*
			Exception thrown when a grade is higher than allowed.
		*/
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		/*
			Exception thrown when a grade is lower than allowed.
		*/
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

/*
	Output stream overload for Bureaucrat.
*/
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
