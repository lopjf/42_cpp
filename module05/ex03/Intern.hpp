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
		
};

#endif