#include <iostream>

// i am defining a template. in the template i declare a type called T
// T can be whatever we want
template <typename T>
// by passing references we can save memory (only pass address of big classes)
// we can also consider inputs as const (the more const the better)
T const & max(T const & x, T const & y)
{
	// if the >= operator has been overloaded, we can use this function with classes
	return( x >= y ? x : y);
}

int main()
{
	int a = 42;
	int b = 21;

	// we need to tell the compiler to instanciate the template
	std::cout << "Max = " << max<int>(a, b) << std::endl;	//explicit instanciation (recommended)

	std::cout << "Max = " << max(a, b) << std::endl;		//implicit instanciation

	// casts like static_cast<int> use templates!

	float c = 4.2;
	float d = 2.1;

	std::cout << "Max = " << max<float>(c, d) << std::endl;
	std::cout << "Max = " << max(c, d) << std::endl;
}