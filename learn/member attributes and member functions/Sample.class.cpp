#include "Sample.class.hpp"

Sample::Sample(void) {

    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample(void) {

    std::cout << "Destructor called" << std::endl;
    return;
}

// definition de la function bar faisant partie de la class Sample
void Sample::bar(void) {
    std::cout << "Member function bar called" << std::endl;
    return;
}
