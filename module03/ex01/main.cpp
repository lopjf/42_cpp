#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {

	// check if I can put all variables in protected instead of private. Evaluation sheet

	ScavTrap scav("PewDiePie");
	scav.guardGate();
	scav.attack("T-Series");
	scav.takeDamage(50);
	scav.beRepaired(30);
	std::cout << std::endl;

	ScavTrap scav2(ScavTrap ("mrBeast"));
	scav2.guardGate();
	scav2.attack("T-Series");
	scav2.takeDamage(50);
	scav2.beRepaired(30);
	std::cout << std::endl;

	ScavTrap scav3 = ScavTrap ("Dude Perfect");
	scav3.guardGate();
	scav3.attack("T-Series");
	scav3.takeDamage(50);
	scav3.beRepaired(30);
	std::cout << std::endl;

	return 0;

}
