#include <iostream>

// A prefix: convention to identify abstract classes
class ACharacter
{
	public:
		/*
			= 0 means there is no definition for this method
			so we can't instanciate the class (a behaviour is missing)
			therefore the class will be abstract
		*/
		virtual void attack(std::string const & target) = 0;
		void sayHello(std::string const & target);
};

// Warrior inherits from character
class Warrior : public ACharacter
{
	public:
		// has to define all abstract methods to be usable
		virtual void attack(std::string const & target);
};

// an interface's name starts with I
class ICoffeeMachine
{
	// an interface only has abstract methods, no variables
	virtual void makeCoffee() = 0;
	virtual void drainWater() = 0;
};

void ACharacter::sayHello(std::string const & target)
{
	std::cout << "Hello " << target << std::endl;
}

void Warrior::attack(std::string const & target)
{
	std::cout << "F**k off " << target << std::endl;
}

int main()
{
	// this is ok, a Warrior is a Warrior
	Warrior*	a = new Warrior();

	// this is not ok, a ACharacter is abstract
	// ACharacter*	b = new ACharacter();

	a->sayHello("students");
	a->attack("students");
}