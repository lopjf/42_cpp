#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap()
{
	this->_hitP = 100;
	this->_energyP = 100;
	this->_attackD = 30;
	
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitP = 100;
	this->_energyP = 100;
	this->_attackD = 30;

	std::cout << "\e[0;33mConstructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	this->_hitP = copy._hitP;
	this->_energyP = copy._energyP;
	this->_attackD = copy._attackD;

	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}


// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}


// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	this->_name = assign._name;
	this->_hitP = assign._hitP;
	this->_energyP = assign._energyP;
	this->_attackD = assign._attackD;

	std::cout << "0;33mCopy assignment operator called of FragTrap\e[0m" << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap "<< this->_name << ": Give me a high five!" << std::endl;
}

