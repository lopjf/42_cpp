#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors
		WrongCat();
		WrongCat(const WrongCat &copy);
		
		// Destructor
		virtual ~WrongCat();
		
		// Operators
		WrongCat & operator=(const WrongCat &assign);
		
		void makeSound() const;
		
	private:
		
};

#endif