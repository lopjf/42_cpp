#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {

	// check if I can put all variables in protected instead of private. Evaluation sheet

	DiamondTrap diam("PewDiePie");
	diam.whoAmI();
	diam.highFivesGuys();
	diam.guardGate();
	diam.attack("T-Series");
	diam.takeDamage(50);
	diam.beRepaired(30);
	std::cout << std::endl;

	DiamondTrap diam2(DiamondTrap ("mrBeast"));
	diam2.whoAmI();
	diam2.highFivesGuys();
	diam2.guardGate();
	diam2.attack("T-Series");
	diam2.takeDamage(50);
	diam2.beRepaired(30);
	std::cout << std::endl;

	DiamondTrap diam3 = DiamondTrap ("Dude Perfect");
	diam3.whoAmI();
	diam3.highFivesGuys();
	diam3.guardGate();
	diam3.attack("T-Series");
	diam3.takeDamage(50);
	diam3.beRepaired(30);
	std::cout << std::endl;

	return 0;

}
