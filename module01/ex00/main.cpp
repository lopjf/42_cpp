#include "Zombie.hpp"

int main() {
	Zombie	daryl = newZombie("daryl");
	Zombie	*rick = randomChump("rick");

	delete daryl;
	delete rick;
	return 0;
}