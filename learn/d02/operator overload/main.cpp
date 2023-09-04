// https://github.com/ekmbcd/cpp_video_lessons/tree/main
#include "Integer.class.hpp"

int main()
{
	Integer a(4);
	Integer b(2);
	Integer c(0);

	// first we call addition operator, then assignment
	c = a + b;
	// we use the redirection operator
	std::cout << a << " + " << b << " = " << c << std::endl;
}