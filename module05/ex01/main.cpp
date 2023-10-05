#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form form1("importantDocument", 10, 50);

    std::cout << "Print status about the form state:\n" << form1 << std::endl;
    
    form1.beSigned(Bureaucrat("Bureaucrat1", 11));

    std::cout << std::endl << "Print status about the form state:\n" << form1 << std::endl;

    form1.beSigned(Bureaucrat("Bureaucrat1", 10));

    std::cout << std::endl << "Print status about the form state:\n" << form1 << std::endl;

    return 0;
}