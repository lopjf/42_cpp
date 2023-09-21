#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    int i = 0;

    // array init
    const Animal *animals[2];

    while (i < 1) {
        animals[i++] = new Dog();
    }
    while (i < 2) {
        animals[i++] = new Cat();
    }
    
    std::cout << animals[0]->getType() << std::endl;
    animals[0]->makeSound();
    std::cout << animals[1]->getType() << std::endl;
    animals[1]->makeSound();

    for (int j = 0; j < 2; j++) {
        delete animals[j];
    }

    std::cout << "\n-----------------------\n" << std::endl;

    // test copy
    Dog basic;
    basic.setBrain(0, "I'm Alive?!");
    std::cout << basic.getBrain(0) << std::endl;
    {
        Dog tmp = basic;
        std::cout << tmp.getBrain(0) << std::endl;
    }
    std::cout << basic.getBrain(0) << std::endl;


    return 0;
}