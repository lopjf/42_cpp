
#include <iostream>
#include <iomanip>

// if i dont't specify a type, the compiler will use float
template< typename T = float>
class Vertex
{
private:
	T const _x;
	T const _y;
	T const _z;

	Vertex();

public:
	Vertex(T const & x, T const & y, T const & z) : _x(x), _y(y), _z(z) {}
	~Vertex() {}

	T const & getx() const { return _x; }
	T const & gety() const { return _y; }
	T const & getz() const { return _z; }

};

template< typename T >
std::ostream & operator << (std::ostream & o, Vertex< T > const & rhs)
{
	std::cout.precision(1);
	// sets .0 for floats
	o << std::setiosflags(std::ios::fixed);
	o << rhs.getx() << " " << rhs.gety() << " " <<  rhs.getz();
	return o;
}

int main()
{
	Vertex<int> a(12, 34, 42);
	// empty chevrons: use default (float)
	Vertex<> b(12, 34, 42);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

}