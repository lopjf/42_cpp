#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
// #include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		// Constructors
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		
		// Destructor
		~DiamondTrap();
		
		// Operators
		DiamondTrap & operator=(const DiamondTrap &assign);
		
		void whoAmI();

	private:

		std::string _name;
		
};

#endif