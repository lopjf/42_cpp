#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int integer);
		Fixed(const float number);
		
		// Destructor
		~Fixed();
		
		// Copy operator
		Fixed & operator=(const Fixed &assign);

		// Comparison operators
		bool operator>(const Fixed &a);
		bool operator<(const Fixed &a);
		bool operator>=(const Fixed &a);
		bool operator<=(const Fixed &a);
		bool operator==(const Fixed &a);
		bool operator!=(const Fixed &a);
		
		// Arithmetic operators
		Fixed operator+(const Fixed &a);
		Fixed operator-(const Fixed &a);
		Fixed operator*(const Fixed &a);
		Fixed operator/(const Fixed &a);

		// increment/decrement operators
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		static Fixed & min(Fixed &a, Fixed &b);
		static const Fixed & min(const Fixed &a, const Fixed &b);
		static Fixed & max(Fixed &a, Fixed &b);
		static const Fixed & max(const Fixed &a, const Fixed &b);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int					_fpValue;
		static const int	_nbOfBits = 8;
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Fixed &object);

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
#endif