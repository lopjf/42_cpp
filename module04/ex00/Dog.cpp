#include "Dog.hpp"

// Constructors
Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	this->_type = copy._type;
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}


// Destructor
Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->_type = assign._type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}
