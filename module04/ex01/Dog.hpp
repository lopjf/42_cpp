#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
#include "Animal.hpp"
#include "Brain.hpp"

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
		
		std::string getBrain(int) const;
		void setBrain(int, std::string);
		
	private:
		
		Brain *_brain;
};

#endif