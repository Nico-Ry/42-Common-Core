#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>	// std::string

class AForm;

/*
	Intern:
	- Creates forms based on a string name and a target.
	- If the form name is unknown, prints an explicit error and returns NULL.
*/
class Intern
{
	private:
		AForm	*_formTemplates[3];

	public:
		/* Orthodox Canonical Form */
		Intern();
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern();

		/*
			Creates a form matching formName and target.
			Returns a newly allocated form on success, NULL on failure.
		*/
		AForm	*makeForm(std::string formName, std::string target) const;
};

#endif
