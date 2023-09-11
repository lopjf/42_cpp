#include "Fixed.hpp"

int main( void ) {

	Fixed a;
		// Arithmetic operators
	Fixed const b( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << "Arithmetic operators" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl << std::endl;

		// increment/decrement operators
	std::cout << "increment/decrement operators" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl << std::endl;

		// Comparison operators
	std::cout << "Comparison operators" << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl << std::endl;

		// min max
	std::cout << "min max" << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;

}
