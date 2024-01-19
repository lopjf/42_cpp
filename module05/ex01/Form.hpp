#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

// need to use forward declaration to solve the circular dependency issue.
class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form();
		Form(const Form &copy);
		Form(const std::string name, const int requiredGrade, const int gradeExecute);
		
		// Destructor
		~Form();
		
		// Operators
		Form & operator=(const Form &assign);
		
		// Getters / Setters
		const std::string getName() const;
		bool getSign() const;
		int getRequiredGrade() const;
		int getGradeExecute() const;
		
		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		// Methods
		void beSigned(Bureaucrat &bureaucrat);

	private:
		const std::string _name;
		bool _sign;
		const int _requiredGrade;
		const int _gradeExecute;
		void checkGrade(int grade) const;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object);

#endif