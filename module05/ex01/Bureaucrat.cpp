#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	_grade = copy._grade;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	checkGrade(grade);
	_grade = grade;
}


// Destructor
Bureaucrat::~Bureaucrat()
{
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	_grade = assign._grade;
	return *this;
}

// Exceptions
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

// Getters
const std::string Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

// Methods
// it is reverted because the best grade is 1 and the worst is 150
void Bureaucrat::incrementGrade()
{
	try {
		if (_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		_grade--;
	}
	catch (GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}
void Bureaucrat::decrementGrade()
{
	try {
		if (_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		_grade++;
	}
	catch (GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}
void Bureaucrat::signForm(Form &form)
{
	if (form.getSign())
		std::cout << getName() << " signed " << form.getName() << std::endl;
	else
		std::cout << getName() << " couldn’t sign " << form.getName() << " because " << getName() << " has a grade " << getGrade() << " and " << form.getName() << " requires a grade " << form.getRequiredGrade() << " to be signed." << std::endl;
}
void Bureaucrat::checkGrade(int grade)
{
	// if we catch the error here. It will still initialize the object with the default values.
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << ", bureaucrat grade " << object.getGrade();
	return stream;
}
