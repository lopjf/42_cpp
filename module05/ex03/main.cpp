#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int	main(void)
{
	Bureaucrat b1("Elon", 140);
    Bureaucrat b2("Bill", 65);
    Bureaucrat b3("Steve", 5);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl << std::endl;

    Intern i1;
    AForm *f1 = i1.makeForm("ShrubberyCreationForm", "ShShShShSh");
    AForm *f2 = i1.makeForm("RobotomyRequestForm", "RobotRobot");
    AForm *f3 = i1.makeForm("PresidentialPardonForm", "PresPres");
    AForm *f4 = i1.makeForm("Oups", "Oups");
    if (f4 == NULL){
        std::cout << "f4 = NULL" << std::endl;
    }

    std::cout << std::endl;
	b1.executeForm(*f1);
    std::cout << std::endl;

    f1->beSigned(b1);
    f2->beSigned(b2);
    f3->beSigned(b3);
    std::cout << std::endl;

	b1.executeForm(*f1);
    std::cout << std::endl;

	b3.executeForm(*f1);
	b3.executeForm(*f2);
	b3.executeForm(*f3);
	
    delete f1;
    delete f2;
    delete f3;

	return (0);
}