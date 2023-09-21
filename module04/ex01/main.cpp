#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
    
    // animals[0]->_brain->setIdea(0, "I'm alive ?!")

    std::cout << animals[0]->getType() << std::endl;
    animals[0]->makeSound();
    // std::cout << animals[0]->_brain->getIdea(0) << std::endl;

    std::cout << animals[1]->getType() << std::endl;
    animals[1]->makeSound();

        // test copy
    Dog basic;
    Dog *dog = new Dog();
    dog->setBrain(0, "ok");
    std::cout << dog->getBrain(0) << std::endl;
    // {
    //     Dog tmp = basic;
    // }
    std::cout << basic.getType() << std::endl;

    // array delete
    for (int j = 0; j < 2; j++) {
        delete animals[j];
    }
    delete dog;

    return 0;

    
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << meta->getType() << " " << std::endl;
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // meta->makeSound();
    // j->makeSound();
    // i->makeSound(); //will output the cat sound!


    // const WrongAnimal* Wrongmeta = new WrongAnimal();
    // const WrongAnimal* Wrongi = new WrongCat();
    // const WrongCat* Wrongc = new WrongCat();
    // std::cout << Wrongmeta->getType() << " " << std::endl;
    // std::cout << Wrongi->getType() << " " << std::endl;
    // std::cout << Wrongc->getType() << " " << std::endl;
    // Wrongmeta->makeSound();
    // Wrongi->makeSound();
    // Wrongc->makeSound(); //will output the cat sound!



    // delete meta;
    // delete j;
    // delete i;
    // delete Wrongmeta;
    // delete Wrongi;
    // delete Wrongc;
    return 0;
}