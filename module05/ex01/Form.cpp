#include "Form.hpp"

// Constructors
Form::Form() : _name("Default"), _sign(false), _requiredGrade(1), _gradeExecute(1)
{
}

Form::Form(const Form &copy) : _name(copy.getName()), _sign(copy.getSign()), _requiredGrade(copy.getRequiredGrade()), _gradeExecute(copy.getGradeExecute())
{
}

Form::Form(const std::string name, const int requiredGrade, const int gradeExecute) : _name(name), _sign(false), _requiredGrade(requiredGrade), _gradeExecute(gradeExecute)
{
	checkGrade(requiredGrade);
	checkGrade(gradeExecute);
}


// Destructor
Form::~Form()
{
}


// Operators
Form & Form::operator=(const Form &assign)
{
	_sign = assign.getSign();
	return *this;
}


// Getters / Setters
const std::string Form::getName() const
{
	return this->_name;
}
bool Form::getSign() const
{
	return this->_sign;
}
int Form::getRequiredGrade() const
{
	return this->_requiredGrade;
}
int Form::getGradeExecute() const
{
	return this->_gradeExecute;
}


// Exceptions
const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}
const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}


// Methods
void Form::beSigned(Bureaucrat &bureaucrat)
{
	try {
		if (bureaucrat.getGrade() <= this->getRequiredGrade()) {
			this->_sign = true;
			bureaucrat.signForm(*this);
		}
		else {
			bureaucrat.signForm(*this);
			throw Form::GradeTooLowException();
		}
	}
	catch (GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}
void Form::checkGrade(int grade)
{
	// if we catch the error here. It will still initialize the object with the default values.
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object)
{
	stream << "Form " << object.getName() << " is " << (object.getSign() ? "signed" : "not signed") << ". It requires a grade " << object.getRequiredGrade() << " to be signed and a grade " << object.getGradeExecute() << " to be executed.";
	return stream;
}
