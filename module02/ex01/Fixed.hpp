#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

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
		
		// Operators
		Fixed & operator=(const Fixed &assign);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int					_fpValue;
		static const int	_nbOfBits = 8;
};

std::ostream & operator<<(std::ostream & o, float const & rhs);

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
#endif