#include "ClapTrap.hpp"

int main( void ) {

	ClapTrap instance("loris");

	instance.attack("diogo");
	instance.takeDamage(5);
	instance.takeDamage(5);
	instance.attack("diogo");
	instance.beRepaired(4);
	instance.attack("diogo");

	return 0;

}
