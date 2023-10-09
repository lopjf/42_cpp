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
	std::string form[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	
	int i = 0;
	while (i < 3) {
		if (form[i].compare(name) == 0)
			break;
		i++;
	}

	switch(i) {
		case 0:
			std::cout << "Intern creates the Shrubbery Creation Form" << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates the Robotomy Request Form" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates the Presidential Pardon Form" << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "The form can't be created, it doesn't exist." << std::endl;
	}
	return NULL;
}
