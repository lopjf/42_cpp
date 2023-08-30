#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
	Zombie	*zombie = Zombie(name);
	return zombie;
}