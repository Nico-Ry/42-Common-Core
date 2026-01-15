#include "Form.hpp"
#include "Bureaucrat.hpp"	// Needed here for Bureaucrat::getGrade()
#include <ostream>			// std::ostream

/*
	Default constructor.
	Initializes a valid Form with a default name and default grades.
*/
Form::Form() : _name("default"), _signed(false), _signGrade(75), _execGrade(75)
{
}

/*
	Constructor initializing only the name.
	Initializes a valid Form with default grades.
*/
Form::Form(std::string name) : _name(name), _signed(false), _signGrade(75), _execGrade(75)
{
}

/*
	Constructor initializing name and required grades.
	Grades must be within [1, 150].
*/
Form::Form(std::string name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

/*
	Copy constructor.
	Copies the state of another Form.
*/
Form::Form(const Form &other)
	: _name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
}

/*
	Copy assignment operator.
	Only the signed status can change because the name and grade requirements are const.
*/
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

/*
	Destructor.
*/
Form::~Form()
{
}

/*
	Getters.
*/
const std::string	Form::getName() const { return _name; }
bool				Form::getSigned() const { return _signed; }
int					Form::getSignGrade() const { return _signGrade; }
int					Form::getExecGrade() const { return _execGrade; }

/*
	beSigned():
	- If the bureaucrat grade is high enough, the form becomes signed.
	- If the grade is too low, throws GradeTooLowException.
	- If the form is already signed, it remains signed.
*/
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_signed)
		return;
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

/*
	Exception messages.
*/
const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

/*
	Output stream overload.
	Prints the Form information.
*/
std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName() << ", form ";
	if (f.getSigned())
		out << "is signed";
	else
		out << "is not signed";
	out << ", sign grade " << f.getSignGrade()
		<< ", execute grade " << f.getExecGrade();
	return out;
}
