#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm(const std::string &target);
		
		// Destructor
		~ShrubberyCreationForm();
		
		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		
		// Getters / Setters
		const std::string getTarget() const;
		
		// Methods
		virtual void execute(Bureaucrat const & executor) const;
		
	private:
		
		const std::string _target; 
};

#endif