#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	// It converts it to the corresponding fixed-point value.
	(void)integer;
}

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;
	// It converts it to the corresponding fixed-point value.
	(void)number;
}


// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(assign.getRawBits());
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fpValue;
}

void Fixed::setRawBits( int const raw ) {
	this->_fpValue = raw;
	return;
}

float Fixed::toFloat( void ) const {
	// that converts the fixed-point value to a floating-point value.
	return (1.1);
}

int Fixed::toInt( void ) const {
	// that converts the fixed-point value to an integer value.
	return 0;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	// i just redirect the value of the Integer (ostream already has an overload for int)
	o << rhs.getRawBits();
	return (o);
}
