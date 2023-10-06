#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), copy.getRequiredGrade(), copy.getGradeExecute()), _target(copy.getTarget())
{
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}


// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}


// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	AForm::operator=(assign);
	return *this;
}

// Getters / Setters
const std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

// Methods
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecute(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
