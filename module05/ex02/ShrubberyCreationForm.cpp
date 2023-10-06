#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getRequiredGrade(), copy.getGradeExecute()), _target(copy.getTarget())
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	AForm::operator=(assign);
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

	std::string filename = getTarget() + "_shrubbery";
	//c_str() returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
	std::ofstream ofs(filename.c_str());
	if (ofs.is_open())
	{
		ofs << "               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n   `&%\\ ` /%&'    |.|        \\ '|8'\n       |o|        | |         | |\n       |.|        | |         | |\n_//__\\/._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n" << std::endl;;
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
	}
}
