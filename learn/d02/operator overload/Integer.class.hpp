#ifndef INTEGER_CLASS_HPP
#define INTEGER_CLASS_HPP

#include <iostream>

class Integer
{

public:

	Integer(int const n);

	int getValue() const;

	// operator[symbol]
	Integer &	operator=(Integer const & rhs);			// assignment operator
	// i return a reference so i can chain assignments ex: a = b = c;
	Integer		operator+(Integer const & rhs) const;	// addition operator
	// here i return a copy of the result
	/*	
		there can be unary, binary and ternary operators (ternary can't be overloaded)
		the first (hidden) parameter of a member function is the current instance of the class
		(this means if i only specify 1 parameter, in reality i have 2)
	*/

private:

	int _n;
};

// overload of the stream redirection operator <<
// in this case the left operator is an output stream (an already existing class)
// we are not overloading a member function, we are overloading a function
std::ostream & operator<<(std::ostream & o, Integer const & rhs);


#endif // INTEGER_CLASS_HPP