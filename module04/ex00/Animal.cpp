#include "Animal.hpp"

// Constructors
Animal::Animal() : _type("Animal")
{
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	this->_type = copy._type;
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}


// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	this->_type = assign._type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "RRrrrRRRrrrrr" << std::endl;
}

std::string Animal::getType() const
{
	// std::cout << this->_type << std::endl;
	return this->_type;
}
