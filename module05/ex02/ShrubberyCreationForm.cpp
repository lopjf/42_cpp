#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	// std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getRequiredGrade(), copy.getGradeExecute()), _target(copy.getTarget())
{
	// std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	// std::cout << "\e[0;33mConstructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	(void) assign;
	return *this;
}

// Getters / Setters
const std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

// Methods
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecute(executor);
	std::cout << "Do things..." << std::endl;
}
