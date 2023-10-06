#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib> 
# include <ctime>
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm(const std::string &target);
		
		// Destructor
		~RobotomyRequestForm();
		
		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);
		
		// Getters / Setters
		const std::string getTarget() const;
		
		// Methods
		virtual void execute(Bureaucrat const & executor) const;
		
	private:
		
		const std::string _target; 
};

#endif