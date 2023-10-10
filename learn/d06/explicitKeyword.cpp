#include <iostream>

class A {};
class B {};

class C 
{
public:
	// a constructor is similar to a cast from A to C
	C(A const & _) {};
	// explicit means we can't implicitly costruct C from B
	explicit C(B const & _) {};
};

void f(C const & _) {}

int main()
{
	f(A());		// implicit conversion -> ok (from A to C)
//	f(B());		// implicit conversion -> compiler error (from B to C)

}