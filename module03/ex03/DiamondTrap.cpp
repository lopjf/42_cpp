#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	ClapTrap::_name = _name + "_clap_name";
	this->_name = _name;
	this->_hitP = FragTrap::defaultHitPoints;
	this->_energyP = ScavTrap::defaultEnergyPoints;
	this->_attackD = FragTrap::defaultAttackDamage;
	std::cout << "\e[0;33mDefault Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitP = FragTrap::defaultHitPoints;
	this->_energyP = ScavTrap::defaultEnergyPoints;
	this->_attackD = FragTrap::defaultAttackDamage;

	std::cout << "\e[0;33mConstructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ScavTrap(copy), FragTrap(copy)
{
	this->_name = copy._name;
	this->_hitP = copy._hitP;
	this->_energyP = copy._energyP;
	this->_attackD = copy._attackD;

	std::cout << "\e[0;33mCopy Constructor called of DiamondTrap\e[0m" << std::endl;
}


// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31mDestructor called of DiamondTrap\e[0m" << std::endl;
}


// Operators
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &assign)
{
	this->_name = assign._name;
	this->_hitP = assign._hitP;
	this->_energyP = assign._energyP;
	this->_attackD = assign._attackD;

	std::cout << "0;33mCopy assignment operator called of DiamondTrap\e[0m" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

