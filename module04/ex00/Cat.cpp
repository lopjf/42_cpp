#include "Cat.hpp"

// Constructors
Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->_type = copy._type;
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}


// Destructor
Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->_type = assign._type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaw Miaw" << std::endl;
}
