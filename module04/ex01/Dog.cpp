#include "Dog.hpp"
#include "Brain.hpp"

// Constructors
Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of Dog" << std::endl;
}

// Destructor
Dog::~Dog()
{
	delete this->_brain;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->_type = assign._type;
	this->_brain = assign._brain;
	std::cout << "\e[0;33mAssignation operator Constructor called of Dog\e[0m" << std::endl;
	return *this;
}

std::string Dog::getBrain(int i) const
{
	return (this->_brain->getIdea(i));
}

void Dog::setBrain(int i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}


void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}
