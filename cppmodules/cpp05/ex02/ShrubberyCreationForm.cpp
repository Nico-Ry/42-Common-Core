#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>		// std::ofstream

/*
	Default constructor.
	Creates a ShrubberyCreationForm with a default target.
	Required grades (subject):
	- sign: 145
	- execute: 137
*/
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

/*
	Constructor with target.
*/
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

/*
	Copy constructor.
*/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original)
	: AForm(original), _target(original._target)
{
}

/*
	Copy assignment operator.
	The target is const and cannot be reassigned.
*/
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original)
{
	(void)original;
	return *this;
}

/*
	Destructor.
*/
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
	Returns the target.
*/
std::string	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

/*
	Executes the shrubbery creation.
	Checks enforced:
	- The form must be signed.
	- The executor must have sufficient grade.
*/
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	/*
		Execution permission checks.
	*/
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();

	/*
		Create the output file.
	*/
	std::ofstream	file((_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw FileOpenException();

	/*
		Write ASCII trees to the file.
	*/
	file << "                                                         .\n"
		 << "                                              .         ;\n"
		 << "                 .              .              ;%     ;;\n"
		 << "                   ,           ,                :;%  %;\n"
		 << "                    :         ;                   :;%;'     .,\n"
		 << "           ,.        %;     %;            ;        %;'    ,;\n"
		 << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
		 << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
		 << "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
		 << "                `%;.     ;%;     %;'         `;%%;.%;'\n"
		 << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
		 << "                    `:%;.  :;bd%;          %;@%;'\n"
		 << "                      `@%:.  :;%.         ;@@%;'\n"
		 << "                        `@%.  `;@%.      ;@@%;\n"
		 << "                          `@%%. `@%%    ;@@%;\n"
		 << "                            ;@%. :@%%  %@@%;\n"
		 << "                              %@bd%%%bd%%:;\n"
		 << "                                #@%%%%%:;;\n"
		 << "                                %@@%%%::;\n"
		 << "                                %@@@%(o);  . '\n"
		 << "                                %@@@o%;:(.,'\n"
		 << "                            `.. %@@@o%::;\n"
		 << "                               `)@@@o%::;\n"
		 << "                                %@@(o)::;\n"
		 << "                               .%@@@@%::;\n"
		 << "                               ;%@@@@%::;.\n"
		 << "                              ;%@@@@%%:;;;.\n"
		 << "                          ...;%@@@@@%%:;;;;,..\n";
	file.close();
}

/*
	Exception message when file creation fails.
*/
const char	*ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "Failed to create shrubbery file";
}

/*
	Optional output stream overload.
*/
std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &s)
{
	out << s.getName() << " targeting " << s.getTarget();
	return out;
}


