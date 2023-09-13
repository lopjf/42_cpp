#include "ClapTrap.hpp"

int main( void ) {

	ClapTrap instance("PewDiePie");

	instance.attack("mrBeast");
	instance.takeDamage(5);
	instance.takeDamage(5);
	instance.attack("mrBeast");
	instance.beRepaired(4);
	instance.attack("mrBeast");

	return 0;

}
