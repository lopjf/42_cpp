#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	this->_type = copy._type;
	std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}


// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	this->_type = assign._type;
	std::cout << "\e[0;33mAssignation operator Constructor called of WrongCat\e[0m" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Miaw Miaw" << std::endl;
}
