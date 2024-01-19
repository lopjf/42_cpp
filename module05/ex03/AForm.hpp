#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

// need to use forward declaration to solve the circular dependency issue.
class Bureaucrat;

class AForm
{
	public:
		// Constructors
		AForm();
		AForm(const AForm &copy);
		AForm(const std::string name, const int requiredGrade, const int gradeExecute);
		
		// Destructor
		virtual ~AForm();
		
		// Operators
		AForm & operator=(const AForm &assign);
		
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
		class FormNotSigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		// Methods
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void checkExecute(Bureaucrat const & executor) const;

	private:
		const std::string _name;
		bool _sign;
		const int _requiredGrade;
		const int _gradeExecute;
		void checkGrade(int grade);
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const AForm &object);

#endif