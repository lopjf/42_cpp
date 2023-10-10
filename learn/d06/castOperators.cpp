#include <iostream>

class Foo
{
public:
	Foo(float const v) : _v(v) {}

	float getV()		{ return _v; }

	// we can overload the casts for a class
	operator float()	{ return _v; }
	operator int()		{ return static_cast<int>(_v); }

private:
	float _v;
};

int main()
{
	Foo a(420.042f);

	// implicit reinterpretation (float to float)
	float	b = a;
	// implicit cast (float to int)
	int		c = a;

	std::cout << b << std::endl;
	std::cout << c << std::endl;

}