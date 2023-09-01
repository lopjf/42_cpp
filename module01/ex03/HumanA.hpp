#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANA_H
# define HUMANA_H

class HumanA {
    private:
        Weapon              &weapon;
        std::string         name;
    
    public:
        
        HumanA(std::string, Weapon&);
        ~HumanA(void);

        void attack();
};

#endif
