#include "Bureaucrat.hpp"
#include "Form.hpp"


int	main(void)
{
    try {
        Form f1("Test", 42, -1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form f2("Test", -1, 42);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form f3("Test", 151, 42);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form f4("Test", 42, 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    Bureaucrat b1("Elon", 2);
    Bureaucrat b2("Bill", 150);
    Bureaucrat b3("Steve", 42);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl << std::endl;

    Form f1("New Dicovery", 10, 1);
    Form f2("Top Secret", 50, 10);
    Form f3("Red Button", 150, 50);
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl << std::endl;
    
    f1.beSigned(b1);
    std::cout << f1 << std::endl << std::endl;
    f2.beSigned(b2);
    std::cout << f2 << std::endl << std::endl;
    f3.beSigned(b3);
    std::cout << f3 << std::endl << std::endl;

	return (0);
}