#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		
		// Destructor
		virtual ~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		
		virtual void makeSound() const;
		
		std::string const getBrain(int) const;
		void setBrain(int, std::string);
		
	private:
		
		Brain *_brain;
};

#endif