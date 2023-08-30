#include "Sample.class.hpp"

// g++ -Wall -Wextra -Wno-unused Sample.class.cpp main.cpp

int main() {
    Sample instance1(42);
    Sample instance2(42);

    // this compare the addresses. so they are different in between instance1 and instance2
    if (&instance1 == &instance1)
        std::cout << "instance1 and instance1 are physically equal" << std::endl;
    else
        std::cout << "instance1 and instance1 are not physically equal" << std::endl;

    if (&instance1 == &instance2)
        std::cout << "instance1 and instance2 are physically equal" << std::endl;
    else
        std::cout << "instance1 and instance2 are not physically equal" << std::endl;
    
    // this compare the strcture of the instance. so they are the same
    if (instance1.compare(&instance1) == 0)
        std::cout << "instance1 and instance1 are structurally equal" << std::endl;
    else
        std::cout << "instance1 and instance1 are not structurally equal" << std::endl;

    if (instance1.compare(&instance2) == 0)
        std::cout << "instance1 and instance2 are structurally equal" << std::endl;
    else
        std::cout << "instance1 and instance2 are not structurally equal" << std::endl;

    return 0;
}