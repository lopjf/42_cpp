#include "AForm.hpp"

// Constructors
AForm::AForm() : _name("Default"), _sign(false), _requiredGrade(1), _gradeExecute(1)
{
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _sign(copy.getSign()), _requiredGrade(copy.getRequiredGrade()), _gradeExecute(copy.getGradeExecute())
{
}

AForm::AForm(const std::string name, const int requiredGrade, const int gradeExecute) : _name(name), _sign(false), _requiredGrade(requiredGrade), _gradeExecute(gradeExecute)
{
	checkGrade(requiredGrade);
	checkGrade(gradeExecute);
}


// Destructor
AForm::~AForm()
{
}


// Operators
AForm & AForm::operator=(const AForm &assign)
{
	_sign = assign.getSign();
	return *this;
}


// Getters / Setters
const std::string AForm::getName() const
{
	return this->_name;
}
bool AForm::getSign() const
{
	return this->_sign;
}
int AForm::getRequiredGrade() const
{
	return this->_requiredGrade;
}
int AForm::getGradeExecute() const
{
	return this->_gradeExecute;
}


// Exceptions
const char * AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}
const char * AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}
const char * AForm::FormNotSigned::what() const throw()
{
	return "The form is not signed.";
}


// Methods
void AForm::beSigned(Bureaucrat &bureaucrat)
{
	try {
		if (bureaucrat.getGrade() <= this->getRequiredGrade()) {
			this->_sign = true;
			bureaucrat.signForm(*this);
		}
		else {
			bureaucrat.signForm(*this);
			throw AForm::GradeTooLowException();
		}
	}
	catch (GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}
void AForm::checkGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}
void AForm::checkExecute(Bureaucrat const & executor) const
{
	if (!getSign())
		throw AForm::FormNotSigned();
	else if (executor.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const AForm &object)
{
	stream << "AForm " << object.getName() << " is " << (object.getSign() ? "signed" : "not signed") << ". It requires a grade " << object.getRequiredGrade() << " to be signed and a grade " << object.getGradeExecute() << " to be executed.";
	return stream;
}
