#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

// need to use forward declaration to solve the circular dependency issue.
class AForm;

class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(const std::string name, int grade);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);
		
		// Getters / Setters
		const std::string getName() const;
		int getGrade() const;
		
		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		// Methods
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const & form);

	private:
		const std::string _name;
		int _grade;
		void checkGrade(int grade);
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif