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

AForm * Intern::shrubbery (std::string target)
{
	std::cout << "Intern creates the Shrubbery Creation Form" << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm * Intern::robotomy (std::string target)
{
	std::cout << "Intern creates the Robotomy Request Form" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm * Intern::presidential (std::string target)
{
	std::cout << "Intern creates the Presidential Pardon Form" << std::endl;
	return new PresidentialPardonForm(target);
}

// Methods
AForm * Intern::makeForm(std::string name, std::string target)
{
	std::string form[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	t_func funcs[] = {&Intern::shrubbery, &Intern::robotomy, &Intern::presidential};

	for (int i = 0; i < 3; i++)
			if (form[i].compare(name) == 0)
				return (this->*funcs[i])(target);

	return NULL;
}
