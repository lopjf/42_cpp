#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _fpValue(0)
{
	// std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy Constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed::Fixed(const int integer) {
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(integer * (1 << this->_nbOfBits));
	// std::cout << this->getRawBits() << std::endl;
}

Fixed::Fixed(const float number) {
	// std::cout << "Float constructor called" << std::endl;
	this->setRawBits(static_cast<int>(roundf(number * static_cast<float>(1 << this->_nbOfBits))));
	// std::cout << this->getRawBits() << std::endl;
}


// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}


// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(assign.getRawBits());
	return *this;
}


// Comparison operators
bool Fixed::operator>(const Fixed &a)
{
	if (this->toFloat() > a.toFloat())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &a)
{
	if (this->toFloat() < a.toFloat())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &a)
{
	if (this->toFloat() >= a.toFloat())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &a)
{
	if (this->toFloat() <= a.toFloat())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &a)
{
	if (this->toFloat() == a.toFloat())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &a)
{
	if (this->toFloat() != a.toFloat())
		return true;
	return false;
}

		
// Arithmetic operators
Fixed Fixed::operator+(const Fixed &a)
{
	Fixed ret = (this->toFloat() + a.toFloat());
	return ret;
}

Fixed Fixed::operator-(const Fixed &a)
{
	Fixed ret = (this->toFloat() - a.toFloat());
	return ret;
}

Fixed Fixed::operator*(const Fixed &a)
{
	Fixed ret = (this->toFloat() * a.toFloat());
	return ret;
}

Fixed Fixed::operator/(const Fixed &a)
{
	Fixed ret = (this->toFloat() / a.toFloat());
	return ret;
}


// increment/decrement operators
Fixed Fixed::operator++()
{
	this->setRawBits(this->_fpValue + 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed pre;

	pre.setRawBits(this->_fpValue);
	this->setRawBits(this->_fpValue + 1);
	return pre;
}

Fixed Fixed::operator--()
{
	this->setRawBits(this->_fpValue - 1);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed pre;
	
	pre.setRawBits(this->_fpValue);
	this->setRawBits(this->_fpValue - 1);
	return pre;
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat()) {
		return b;
	}
	return a;
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat()) {
		return b;
	}
	return a;
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat()) {
		return a;
	}
	return b;
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat()) {
		return a;
	}
	return b;
}

int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fpValue;
}

void Fixed::setRawBits( int const raw ) {
	this->_fpValue = raw;
	return;
}

float Fixed::toFloat( void ) const {
	// that converts the fixed-point value to a floating-point value.

	float ret;

	ret = static_cast<float>(this->getRawBits()) / static_cast<float>(1 << this->_nbOfBits);
	
	return (ret);

}

int Fixed::toInt( void ) const {
	// that converts the fixed-point value to an integer value.

	int ret;

	ret = this->getRawBits() / (1 << this->_nbOfBits);
	
	return (ret);

}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Fixed &object)
{
	stream << object.toFloat();
	return stream;
}
