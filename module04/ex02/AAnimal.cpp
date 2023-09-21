#include "AAnimal.hpp"

// Constructors
AAnimal::AAnimal() : _type("Animal")
{
	std::cout << "\e[0;33mDefault Constructor called of AAnimal\e[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	this->_type = copy._type;
	std::cout << "\e[0;33mCopy Constructor called of AAnimal\e[0m" << std::endl;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "\e[0;31mDestructor called of AAnimal\e[0m" << std::endl;
}


// Operators
AAnimal & AAnimal::operator=(const AAnimal &assign)
{
	this->_type = assign._type;
	std::cout << "\e[0;33mAssignation operator Constructor called of AAnimal\e[0m" << std::endl;
	return *this;
}

void AAnimal::makeSound() const
{
	std::cout << "RRrrrRRRrrrrr" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->_type;
}
