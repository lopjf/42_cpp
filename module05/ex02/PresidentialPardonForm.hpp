#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm(const std::string &target);
		
		// Destructor
		~PresidentialPardonForm();
		
		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		
		// Getters / Setters
		const std::string getTarget() const;
		
		// Methods
		virtual void execute(Bureaucrat const & executor) const;
		
	private:
		
		const std::string _target; 
};

#endif