#include "HumanB.hpp"

void HumanB::attack() {
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon type) {
    // std::cout << type.getType() << std::endl;
    // std::cout << &type << std::endl;

    // this->weapon->setType(type.getType());
    this->weapon = &type;
    // std::cout << this->weapon << std::endl;

    // std::cout << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string humanName) : name(humanName) {
    return;
}

HumanB::~HumanB(void) {
    return;
}