#include <iostream>

#ifndef WEAPON_H
# define WEAPON_H

class Weapon {
    private:
        std::string _type;
    
    public:
        Weapon(std::string);
        ~Weapon(void);

        const std::string getType(void);
        void setType(std::string type);
};

#endif
