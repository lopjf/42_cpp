#include "Zombie.hpp"

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->_name = name;
}

Zombie::Zombie() {
    return;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << ": Died from starvation..." << std::endl;
    return;
}
