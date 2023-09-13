#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() : _name("Default"), _hitP(10), _energyP(10), _attackD(0)
{
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}


ClapTrap::ClapTrap(std::string name) : _name(name), _hitP(10), _energyP(10), _attackD(0)
{
	std::cout << "\e[0;33mConstructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	this->_name = copy._name;
	this->_hitP = copy._hitP;
	this->_energyP = copy._energyP;
	this->_attackD = copy._attackD;

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
	this->_name = assign._name;
	this->_hitP = assign._hitP;
	this->_energyP = assign._energyP;
	this->_attackD = assign._attackD;

	std::cout << "0;33mCopy assignment operator called\e[0m" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	
	if (this->_hitP < 1) {
		std::cout << "Claptrap " << this->_name << " can't attack, it's dead (︶︹︺)." << std::endl;
	} else if (this->_energyP < 1) {
		std::cout << "Claptrap " << this->_name << " doesn't have enough hit points to attack" << std::endl;
	} else {
		this->_energyP--;
		std::cout << "Claptrap " << this->_name << " attacks " << target << ", causing " << this->_attackD << " points of damage! (╰ ‿ ╯)." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (this->_hitP < 1) {
		std::cout << "Claptrap " << this->_name << " is already dead (︶︹︺)." << std::endl;
		return ;
	}

	this->_hitP -= amount;
	if (this->_hitP < 1) {
		std::cout << "Claptrap " << this->_name << " get attacked with " << amount << " attack damage. It died (︶︹︺)." << std::endl;
	} else {
		std::cout << "Claptrap " << this->_name << " get attacked with " << amount << " attack damage. It now has: " << this->_hitP << " hit points left." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitP < 1) {
		std::cout << "Claptrap " << this->_name << " can't repair itself, it's dead (︶︹︺)." << std::endl;
		return ;
	} else if (this->_energyP < 1) {
		std::cout << "Claptrap " << this->_name << " doesn't have enough hit points to repair itself" << std::endl;
		return ;
	} else {
		this->_energyP--;
		this->_hitP += amount;
		std::cout << "Claptrap " << this->_name << " repairs itself, and get " << amount << " hit points back. It now has: " << this->_hitP << " hit points ( ͡° ل͜ ͡°)." << std::endl;
	}
}
