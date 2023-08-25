#include "Sample.class.hpp"

// here, we don't give the value f to pi. We initialize pi to the value of f
Sample::Sample(float const f) : pi(f), qd(42) {

    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample(void) {

    std::cout << "Destructor called" << std::endl;
    return;
}

void Sample::bar(void) const {
    std::cout << "this->pi = " << this->pi << std::endl;
    std::cout << "this->qd = " << this->qd << std::endl;

    // this->qd = 0;   // can't work because the bar function is const

    return;
}
