#include <iostream>

int main()
{
	// reinterpret_cast does not convert, just tell the compiler how to read bits
	
	float	a = 420.042f;						// reference value

	void *	b = &a;								// implicit promotion -> Ok
	int *	c = reinterpret_cast<int *>(b);		// explicit demotion -> Ok i obey
	int &	d = reinterpret_cast<int &>(b);		// explicit demotion -> Ok i obey
	
	std::cout << *c << " - " << d << std::endl;
}