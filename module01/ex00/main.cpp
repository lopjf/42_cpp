#include "Zombie.hpp"

int main() {

	Zombie *rick = newZombie("rick");
	rick->announce();

	randomChump("daryl");

	delete rick;
	return 0;
}
