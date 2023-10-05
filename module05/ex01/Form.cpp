#include "Form.hpp"

// Constructors
Form::Form() : _name("Default"), _sign(false), _requiredGrade(1), _gradeExecute(1)
{
	// std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()), _sign(copy.getSign()), _requiredGrade(copy.getRequiredGrade()), _gradeExecute(copy.getGradeExecute())
{
	// _name = copy.getName();
	// _signed = copy.getSigned();
	// _requiredGrade = copy.getRequiredGrade();
	// _gradeExecute = copy.getGradeExecute();
	// std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const std::string name, const int requiredGrade, const int gradeExecute) : _name(name), _sign(false), _requiredGrade(requiredGrade), _gradeExecute(gradeExecute)
{


	// Can't have initialise a const variable in the constructor body. So that bellow doesn't work.


// init requiredGrade
// 	try {
// 		if (requiredGrade < 1)
// 			throw Form::GradeTooHighException();
// 		else if (requiredGrade > 150)
// 			throw Form::GradeTooLowException();
// 		this->_requiredGrade = requiredGrade;
// 	} catch (GradeTooHighException &e) {
// 		std::cout << e.what() << std::endl;
// 		this->_requiredGrade = 1;
// 	} catch (GradeTooLowException &e) {
// 		std::cout << e.what() << std::endl;
// 		this->_requiredGrade = 1;
// 	}

// // init gradeExecute
// 	try {
// 		if (gradeExecute < 1)
// 			throw Form::GradeTooHighException();
// 		else if (gradeExecute > 150)
// 			throw Form::GradeTooLowException();
// 		this->_gradeExecute = gradeExecute;
// 	} catch (GradeTooHighException &e) {
// 		std::cout << e.what() << std::endl;
// 	} catch (GradeTooLowException &e) {
// 		std::cout << e.what() << std::endl;
// 	}

	// _name = name;
	// _signed = sign;
	// _requiredGrade = requiredGrade;
	// _gradeExecute = gradeExecute;
	// std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
}


// Destructor
Form::~Form()
{
	// std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	// _name = assign.getName();
	_sign = assign.getSign();
	// _requiredGrade = assign.getRequiredGrade();
	// _gradeExecute = assign.getGradeExecute();
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
	return "Grade too high";
}
const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low, Form can't be signed";
}


// Methods
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	try {
		if (bureaucrat.getGrade() <= this->getRequiredGrade()) {
			this->_sign = true;
			bureaucrat.signForm(*this);
		}
		else
			throw Form::GradeTooLowException();
	}
	catch (GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object)
{
	stream << "Form " << object.getName() << " is " << (object.getSign() ? "signed" : "not signed") << " and requires a grade " << object.getRequiredGrade() << " to be signed and a grade " << object.getGradeExecute() << " to be executed." << std::endl;
	return stream;
}
