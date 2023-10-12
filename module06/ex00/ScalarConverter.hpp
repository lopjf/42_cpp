#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <limits>
# include <iomanip>

class ScalarConverter
{
	public:
	
		// Methods
		void static convert(std::string str);
		
	private:
		
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		
		// Destructor
		~ScalarConverter();
		
		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);
};

bool isNumber(const std::string str);


#endif