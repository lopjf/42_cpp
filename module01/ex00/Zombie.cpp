#include "Zombie.hpp"

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
    return;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << ": Died from starvation..." << std::endl;
    return;
}
