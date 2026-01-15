#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
	Default constructor.
	Initializes a valid form with default values.
*/
AForm::AForm() : _name("default"), _signed(false), _signGrade(75), _execGrade(75)
{
}

/*
	Constructor initializing only the name.
	Initializes valid default grades.
*/
AForm::AForm(std::string name) : _name(name), _signed(false), _signGrade(75), _execGrade(75)
{
}

/*
	Constructor initializing name and required grades.
	Grades must be within [1, 150].
*/
AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

/*
	Copy constructor.
*/
AForm::AForm(const AForm &original)
	: _name(original._name),
	_signed(original._signed),
	_signGrade(original._signGrade),
	_execGrade(original._execGrade)
{
}

/*
	Copy assignment operator.
	Only the signed state can be assigned because the other attributes are const.
*/
AForm &AForm::operator=(const AForm &original)
{
	if (this != &original)
		_signed = original._signed;
	return *this;
}

/*
	Virtual destructor for proper cleanup through base-class pointers.
*/
AForm::~AForm()
{
}

/*
	Getters.
*/
const std::string	AForm::getName() const { return _name; }
bool				AForm::getSigned() const { return _signed; }
int					AForm::getSignGrade() const { return _signGrade; }
int					AForm::getExecGrade() const { return _execGrade; }

/*
	beSigned():
	- If already signed, no state change is needed.
	- Signs the form if the bureaucrat grade is sufficient.
	- Throws GradeTooLowException otherwise.
*/
void	AForm::beSigned(const Bureaucrat &bureaucrat)
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
const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

/*
	Output stream overload.
*/
std::ostream	&operator<<(std::ostream &out, const AForm &f)
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
