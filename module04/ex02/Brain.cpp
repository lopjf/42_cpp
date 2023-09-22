#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
	{
		this->setIdea(i, copy._ideas[i]);
	}
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}


// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}

// Operators
Brain & Brain::operator=(const Brain &assign)
{
	for (int i = 0; i < 100; i++)
	{
		this->setIdea(i, assign._ideas[i]);
	}
	std::cout << "\e[0;33mAssignation operator Constructor called of Brain\e[0m" << std::endl;
	return *this;
}


std::string const Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	this->_ideas[i] = idea;
}
