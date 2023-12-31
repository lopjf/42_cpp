#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->_type = copy._type;
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}


// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->_type = assign._type;
	std::cout << "\e[0;33mAssignation operator Constructor called of WrongAnimal\e[0m" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "RRrrrRRRrrrrr" << std::endl;
}

std::string const WrongAnimal::getType() const
{
	return this->_type;
}
