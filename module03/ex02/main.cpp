#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {

	// check if I can put all variables in protected instead of private. Evaluation sheet

	FragTrap frag("PewDiePie");
	frag.highFivesGuys();
	frag.attack("T-Series");
	frag.takeDamage(50);
	frag.beRepaired(30);
	std::cout << std::endl;

	FragTrap frag2(FragTrap ("mrBeast"));
	frag2.highFivesGuys();
	frag2.attack("T-Series");
	frag2.takeDamage(50);
	frag2.beRepaired(30);
	std::cout << std::endl;

	FragTrap frag3 = FragTrap ("Dude Perfect");
	frag3.highFivesGuys();
	frag3.attack("T-Series");
	frag3.takeDamage(50);
	frag3.beRepaired(30);
	std::cout << std::endl;

	return 0;

}
