#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		// Constructors
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		
		// Destructor
		~ScavTrap();
		
		// Operators
		ScavTrap & operator=(const ScavTrap &assign);
		
		void attack(const std::string& target);
		void guardGate();

	protected:

		static const int defaultHitPoints = 100;
		static const int defaultEnergyPoints = 50;
		static const int defaultAttackDamage = 20;
		
};

#endif