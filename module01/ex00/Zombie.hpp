#include <iostream>
#include <string>

#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie {
private:
	std::string _name;

public:
	Zombie(std::string);
	~Zombie(void);
	
	void announce(void);

};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif
