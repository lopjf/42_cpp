#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
		
		std::string const getBrain(int) const;
		void setBrain(int, std::string);
		
	private:
		
		Brain *_brain;
};

#endif