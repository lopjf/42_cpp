#include "Zombie.hpp"

void Zombie::announce() {
	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}

Zombie::~Zombie( void ) {
    return;
}