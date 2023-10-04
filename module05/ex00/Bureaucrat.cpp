#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	this->_grade = copy._grade;
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = grade;
	} catch (GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		this->_grade = 1;
	} catch (GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		this->_grade = 150;
	}
	
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	// can't assign to _name because it is const.
	this->_grade = assign._grade;
	return *this;
}


// Getters
const std::string Bureaucrat::getName() const
{
	return this->_name;
}
int Bureaucrat::getGrade() const
{
	return this->_grade;
}

// it is reverted because the best grade is 1 and the worst is 150
void Bureaucrat::incrementGrade()
{
	try {
		if (this->_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade--;
	}
	catch (GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}
void Bureaucrat::decrementGrade()
{
	try {
		if (this->_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
	}
	catch (GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << ", bureaucrat grade " << object.getGrade();
	return stream;
}
