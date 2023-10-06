#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int	main(void)
{
	Bureaucrat b1("Elon", 140);
    Bureaucrat b2("Bill", 65);
    Bureaucrat b3("Steve", 5);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl << std::endl;

    ShrubberyCreationForm f1("ShShShShSh");
    RobotomyRequestForm f2("RobotRobot");
    PresidentialPardonForm f3("PresPres");
    
	b1.executeForm(f1);
    std::cout << std::endl;

    f1.beSigned(b1);
    f2.beSigned(b2);
    f3.beSigned(b3);
    std::cout << std::endl;

	b1.executeForm(f1);
    std::cout << std::endl;

	b3.executeForm(f1);
	b3.executeForm(f2);
	b3.executeForm(f3);
	
	return (0);
}