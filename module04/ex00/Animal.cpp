#include "Animal.hpp"

// Constructors
Animal::Animal()
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

void const Animal::makeSound()
{
	std::cout << "RRrrrRRRrrrrr" << std::endl;
}

void const Animal::getType()
{
	std::cout << this->_type << std::endl;
}
