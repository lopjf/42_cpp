#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);
		
		// Methods
		AForm * makeForm(std::string name, std::string target);

	private:
	
		AForm * shrubbery (std::string target);
		AForm * robotomy (std::string target);
		AForm * presidential (std::string target);
};

typedef	AForm* (Intern::*t_func)(std::string);

#endif