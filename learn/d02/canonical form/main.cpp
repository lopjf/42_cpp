#include "Sample.class.hpp"

int main()
{
	Sample s;
	Sample p(12);
	Sample c(p);
	
	s = p;

	std::cout << "s = " << s << "\tp = " << p << "\tc = " << c << std::endl;
}