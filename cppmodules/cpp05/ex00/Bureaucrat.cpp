#include "Bureaucrat.hpp"
#include <ostream>

/*
	Default constructor.
	Initializes a valid Bureaucrat with a default name and grade.
*/
Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{
}

/*
	Constructor initializing only the name.
	The grade is set to a valid default value.
*/
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(75)
{
}

/*
	Constructor initializing name and grade.
	The grade must be within the allowed range [1, 150].
*/
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

/*
	Constructor initializing only the grade.
	The grade must be within the allowed range [1, 150].
*/
Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

/*
	Copy constructor.
	Copies the state of another Bureaucrat.
*/
Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other.getName()), _grade(other.getGrade())
{
}

/*
	Copy assignment operator.
	The name is const and cannot be reassigned.
*/
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other.getGrade();
	return *this;
}

/*
	Destructor.
*/
Bureaucrat::~Bureaucrat()
{
}

/*
	Returns the Bureaucrat's name.
*/
const std::string Bureaucrat::getName() const
{
	return _name;
}

/*
	Returns the Bureaucrat's grade.
*/
int Bureaucrat::getGrade() const
{
	return _grade;
}

/*
	Increases the Bureaucrat's rank.
	Grade 1 is the highest possible value.
*/
void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

/*
	Decreases the Bureaucrat's rank.
	Grade 150 is the lowest possible value.
*/
void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

/*
	Exception message for grades that are too high.
*/
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

/*
	Exception message for grades that are too low.
*/
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

/*
	Output stream overload.
	Prints the Bureaucrat in the required format.
*/
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
