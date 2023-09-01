#include <iostream>
#include <string>

#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie {
private:
	std::string _name;

public:
	Zombie();
	~Zombie(void);
	
	void announce(void);
	void setName(std::string name);

};

Zombie* zombieHorde( int N, std::string name );

#endif