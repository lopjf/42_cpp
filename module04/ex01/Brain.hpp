#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);
		
		// Destructor
		virtual ~Brain();
		
		// Operators
		Brain & operator=(const Brain &assign);

		std::string const getIdea(int) const;
		void setIdea(int, std::string);

	private:

		std::string _ideas[100];

		

};

#endif