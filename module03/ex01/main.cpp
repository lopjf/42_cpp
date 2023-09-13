#include "ClapTrap.hpp"

int main( void ) {

	ClapTrap instance("PewDiePie");

	instance.attack("mrBeast");
	instance.takeDamage(5);
	instance.beRepaired(3);
	instance.attack("mrBeast");
	instance.attack("mrBeast");
	instance.attack("mrBeast");
	instance.attack("mrBeast");
	instance.attack("mrBeast");
	instance.attack("mrBeast");
	instance.attack("mrBeast");
	instance.attack("mrBeast");
	instance.attack("mrBeast");
	instance.beRepaired(3);
	instance.takeDamage(10);
	instance.takeDamage(10);
	instance.attack("mrBeast");
	instance.beRepaired(3);

	return 0;

}
