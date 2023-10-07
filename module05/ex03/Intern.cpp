#include "Intern.hpp"

// Constructors
Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}


// Destructor
Intern::~Intern()
{
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

// Methods
AForm * Intern::makeForm(std::string name, std::string target)
{
	AForm *form;
	if (name == "ShrubberyCreationForm")
		form = new ShrubberyCreationForm(target);
	else if (name == "RobotomyRequestForm")
		form = new RobotomyRequestForm(target);
	else if (name == "PresidentialPardonForm")
		form = new PresidentialPardonForm(target);
	else {
		std::cout << "The form can't be created, it doesn't exist." << std::endl;
		return NULL;
	}
	std::cout << "Intern creates: " << name << std::endl;
	return form;
}
