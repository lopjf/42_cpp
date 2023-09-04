// https://github.com/ekmbcd/cpp_video_lessons/tree/main
#include "Integer.class.hpp"

Integer::Integer(int const n) : _n(n) { }

int Integer::getValue() const
{
	return(_n);
}

Integer & Integer::operator=(Integer const & rhs)
{
	std::cout << "Assignment operator called." << std::endl;
	// update _n of my current instance
	this->_n = rhs.getValue();
	return (*this);
}

Integer Integer::operator+(Integer const & rhs) const
{
	int sum;

	std::cout << "Addition operator called." << std::endl;
	sum = this->getValue() + rhs.getValue();
	// returns a new Integer
	return (Integer(sum));
}


std::ostream & operator<<(std::ostream & o, Integer const & rhs)
{
	// i just redirect the value of the Integer (ostream already has an overload for int)
	o << rhs.getValue();
	return (o);
}