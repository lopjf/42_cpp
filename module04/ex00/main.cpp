#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    meta->makeSound();
    j->makeSound();
    i->makeSound(); //will output the cat sound!


    const WrongAnimal* Wrongmeta = new WrongAnimal();
    const WrongAnimal* Wrongi = new WrongCat();
    std::cout << Wrongmeta->getType() << " " << std::endl;
    std::cout << Wrongi->getType() << " " << std::endl;
    Wrongmeta->makeSound();
    Wrongi->makeSound(); //will output the cat sound!


    delete meta;
    delete j;
    delete i;
    return 0;
}