#include "Fixed.hpp"

// Constructors
Fixed::Fixed() : _fpValue(0)
{
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
}


// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}


// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	(void) assign;
	return *this;
}

int getRawBits( void ) const {

}

void setRawBits( int const raw ) {

}
