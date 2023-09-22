#include "Cat.hpp"
#include "Brain.hpp"

// Constructors
Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}


// Destructor
Cat::~Cat()
{
	delete this->_brain;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->_type = assign._type;
	this->_brain = new Brain(*assign._brain);
	std::cout << "\e[0;33mAssignation operator Constructor called of Cat\e[0m" << std::endl;
	return *this;
}

std::string const Cat::getBrain(int i) const
{
	return (this->_brain->getIdea(i));
}

void Cat::setBrain(int i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}

void Cat::makeSound() const
{
	std::cout << "Miaw Miaw" << std::endl;
}
