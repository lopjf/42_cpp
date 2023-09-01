#include "Weapon.hpp"

const std::string Weapon::getType() {
    return this->_type;
}

void Weapon::setType(std::string type) {
    this->_type = type;
}

Weapon::Weapon(std::string weaponType) : _type(weaponType) {
    return;
}

Weapon::~Weapon(void) {
    return;
}