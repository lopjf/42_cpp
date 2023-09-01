#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANB_H
# define HUMANB_H

class HumanB {
    private:
        Weapon              *weapon;
        std::string         name;
    
    public:
        
        HumanB(std::string);
        ~HumanB(void);

        void attack();
        void setWeapon(Weapon type);
};

#endif
