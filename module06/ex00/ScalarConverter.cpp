#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}


// Destructor
ScalarConverter::~ScalarConverter()
{
}


// Methods
void ScalarConverter::convert(std::string str)
{

	char *pEnd;

	// char	cha;
	// int		num;
	// float	flo;
	double	dou;

	// use strtod (for float and double?)
	dou = strtod(&str[0], &pEnd);

	std::cout << dou << std::endl;
}


// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return *this;
}

