#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int	main(void)
{
	Bureaucrat b1("Elon", 2);
    Bureaucrat b2("Bill", 150);
    Bureaucrat b3("Steve", 42);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl << std::endl;

    ShrubberyCreationForm f1("Home");
    // RobotomyRequestForm f2("Home");
    // PresidentialPardonForm f3("Home");
    std::cout << f1 << std::endl;
    // std::cout << f2 << std::endl;
    // std::cout << f3 << std::endl << std::endl;
    
	b1.executeForm(f1);

    f1.beSigned(b1);
    std::cout << f1 << std::endl << std::endl;

	b2.executeForm(f1);
	b1.executeForm(f1);
	
	return (0);
}