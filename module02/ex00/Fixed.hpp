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
		
		// Destructor
		~Fixed();
		
		// Operators
		Fixed & operator=(const Fixed &assign);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int				_fpValue;
		static const	_nbOfBits;
};

#endif