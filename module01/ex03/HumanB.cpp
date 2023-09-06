#include "HumanB.hpp"

void HumanB::attack() {
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &type) {
    this->weapon = &type;
}

HumanB::HumanB(std::string humanName) : name(humanName) {
    return;
}

HumanB::~HumanB(void) {
    return;
}