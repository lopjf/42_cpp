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
		Fixed & operator>(const Fixed);
		Fixed & operator<(const Fixed);
		Fixed & operator>=(const Fixed);
		Fixed & operator<=(const Fixed);
		Fixed & operator==(const Fixed);
		Fixed & operator!=(const Fixed);
		
		// Arithmetic operators
		Fixed operator+(const Fixed &instance);
		Fixed operator-(const Fixed &instance);
		Fixed operator*(const Fixed &instance);
		Fixed operator/(const Fixed &instance);

		// increment/decrement operators
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);


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