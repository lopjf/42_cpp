#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		
		// Destructor
		virtual ~Dog();
		
		// Operators
		Dog & operator=(const Dog &assign);
		
		virtual void makeSound() const;
		
	private:
		
};

#endif