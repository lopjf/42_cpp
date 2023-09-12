#include <iostream>
#include "sample.class.hpp"

//define a function from a class (similar to a namespace)
Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}