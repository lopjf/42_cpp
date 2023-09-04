#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP

#include <iostream>

/* 
	a class is in a canonical form if it has at least a default
	constructor, a copy constructor, an assignment overload and a destructor
*/
// unless specified, all classes we create should be canonical
class Sample
{

public:

	Sample(void);								// canonical
	Sample(int const n);
	Sample(Sample const & src);					// canonical (copy constructor)
	~Sample();									// canonical

	Sample & operator=(Sample const & rhs);		// canonical

	int getFoo() const;

private:

	int _foo;
};

std::ostream & operator<<(std::ostream & o, Sample const & i);

#endif