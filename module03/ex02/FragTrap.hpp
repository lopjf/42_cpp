#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Constructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		
		// Destructor
		~FragTrap();
		
		// Operators
		FragTrap & operator=(const FragTrap &assign);
		
		void highFivesGuys(void);

	private:
		
};

#endif