#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap(std::string name) : _name(name), _hitP(10), _energyP(10), _attackD(0)
{
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}


// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
}


// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	(void) assign;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	
	if (this->_hitP < 1) {
		std::cout << "Claptrap " << this->_name << " doesn't have enough hit points to attack" << std::endl;
	} else if (this->_energyP < 1) {
		std::cout << "Claptrap " << this->_name << " doesn't have enough energy points to attack" << std::endl;
	} else {
		this->_energyP -= 1;
		std::cout << "Claptrap " << this->_name << " attacks " << target << ", causing " << this->_attackD << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_hitP -= amount;
	std::cout << "Claptrap " << this->_name << " get attacked with " << amount << " attack damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyP > 0) {
		this->_energyP -= 1;
		this->_hitP += amount;
		std::cout << "Claptrap " << this->_name << " repairs itself, and get " << amount << " hit points back" << std::endl;
	} else {
		std::cout << "Claptrap " << this->_name << " doesn't have enough energy points to repair itself" << std::endl;

	}
}
