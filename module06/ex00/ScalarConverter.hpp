#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
#include <stdlib.h>

class ScalarConverter
{
	public:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		
		// Destructor
		~ScalarConverter();
		
		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);
		
		// Methods
		void convert(std::string str);
		
	private:
		
};

#endif