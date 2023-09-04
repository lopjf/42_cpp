#include "Sample.class.hpp"

Sample::Sample() : _foo(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Sample::Sample(int const n) : _foo(n)
{
	std::cout << "Parametric constructor called" << std::endl;
}

Sample::Sample(Sample const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	// the copy constructor calls the assignment operator
	*this = src;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
}

Sample & Sample::operator=(Sample const & rhs)
{
	std::cout << "Assignment operator called." << std::endl;
	this->_foo = rhs.getFoo();
	return (*this);
}

int Sample::getFoo() const
{
	return(_foo);
}

std::ostream & operator<<(std::ostream & o, Sample const & rhs)
{
	o << rhs.getFoo();
	return (o);
}