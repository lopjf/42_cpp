#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
#include "Brain.hpp"

class AAnimal
{
	public:
		// Constructors
		AAnimal();
		AAnimal(const AAnimal &copy);

		// Destructor
		virtual ~AAnimal();
		
		// Operators
		AAnimal & operator=(const AAnimal &assign);
		
		virtual void makeSound() const = 0;

		std::string const getType() const;

	protected:
		std::string _type;

};

#endif