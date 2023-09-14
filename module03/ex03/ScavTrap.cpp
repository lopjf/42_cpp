#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitP = this->defaultHitPoints;
	this->_energyP = this->defaultEnergyPoints;
	this->_attackD = this->defaultAttackDamage;
	
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitP = this->defaultHitPoints;
	this->_energyP = this->defaultEnergyPoints;
	this->_attackD = this->defaultAttackDamage;

	std::cout << "\e[0;33mConstructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	this->_hitP = copy._hitP;
	this->_energyP = copy._energyP;
	this->_attackD = copy._attackD;

	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}


// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}


// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	this->_name = assign._name;
	this->_hitP = assign._hitP;
	this->_energyP = assign._energyP;
	this->_attackD = assign._attackD;

	std::cout << "0;33mCopy assignment operator called of ScavTrap\e[0m" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	
	if (this->_hitP < 1) {
		std::cout << "ScavTrap " << this->_name << " can't attack, it's dead (︶︹︺)." << std::endl;
	} else if (this->_energyP < 1) {
		std::cout << "ScavTrap " << this->_name << " doesn't have enough hit points to attack" << std::endl;
	} else {
		this->_energyP--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackD << " points of damage! (╰ ‿ ╯). It now has: " << this->_energyP << " energy points." << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap "<< this->_name << " has entered in Gate keeper mode." << std::endl;
}

