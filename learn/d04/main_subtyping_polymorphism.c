#include <iostream>

class Character
{
public:
	// virtual means the compiler will look through inheritance and use the correct overload
	// a virtual member function is called "method" (a member function with dynamic resolution)
	// virtual
	void sayHello(std::string const & target);
};

// Warrior inherits from character
class Warrior : public Character
{
public:
	// Warrior overloads Character's sayHello function
	void sayHello(std::string const & target);
};

class Cat
{
	// Cat has nothing to do with Character
};

void Character::sayHello(std::string const & target)
{
	std::cout << "Hello " << target << std::endl;
}

void Warrior::sayHello(std::string const & target)
{
	std::cout << "F**k off " << target << std::endl;
}

int main()
{
	// this is ok, a Warrior is a Warrior
	Warrior*	a = new Warrior();

	// this is ok, a Warrior is a Character
	Character*	b = new Warrior();

	// this is not ok, a Character is not (necessarily) a Warrior
	// Warrior*	c = new Warrior();

	// this is not ok, Cat is not related to Character
	// Character*	d = new Cat();

	// a uses the Warrior overloaded function
	a->sayHello("students");

	// even if b is a Warrior, it still uses the Character function
	// (because it is considered a Character pointer)
	b->sayHello("students");
}