#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);
    Bureaucrat b3("b3", 0);
    Bureaucrat b4("b4", 151);

    std::cout << std::endl;

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    std::cout << b4 << std::endl;

    std::cout << std::endl;

    std::cout << "b1 name is: " << b1.getName() << std::endl;
    std::cout << "b1 grade is: " << b1.getGrade() << std::endl;

    std::cout << std::endl;

    b1.incrementGrade();
    b2.decrementGrade();
    b3.decrementGrade();
    b4.incrementGrade();

    std::cout << std::endl;
    
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    std::cout << b4 << std::endl;

    return 0;
}