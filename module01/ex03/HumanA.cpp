#include "HumanA.hpp"

void HumanA::attack() {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string humanName, Weapon &type) : weapon(type), name(humanName){
    return;
}

HumanA::~HumanA(void) {
    return;
}