#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << meta->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    meta->makeSound();
    dog->makeSound();
    cat->makeSound(); //will output the cat sound!


    const WrongAnimal* Wrongmeta = new WrongAnimal();
    const WrongAnimal* Wrongcat = new WrongCat();
    const WrongCat* Wrongc = new WrongCat();
    std::cout << Wrongmeta->getType() << " " << std::endl;
    std::cout << Wrongcat->getType() << " " << std::endl;
    std::cout << Wrongc->getType() << " " << std::endl;
    Wrongmeta->makeSound();
    Wrongcat->makeSound();  // will output animal sound!
    Wrongc->makeSound(); //will output the cat sound!



    delete meta;
    delete dog;
    delete cat;
    delete Wrongmeta;
    delete Wrongcat;
    delete Wrongc;
    return 0;
}