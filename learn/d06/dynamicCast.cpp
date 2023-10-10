#include <iostream>
#include <typeinfo>
#include <exception>

class Parent {public: virtual ~Parent() {} };

class Child1 : public Parent {};
class Child2 : public Parent {};

// dynamic cast only happens at runtime
// the compiler does not check if it fails
// it will only work with polymorphic instances (subtype polymorphism = at least a virtual function)

int main()
{
	Child1		a;				// reference value
	Parent *	b = &a;			// implict upcast -> Ok

	// dynamic_cast is used only for downcast

	// explict downcast (with pointer) -> Ok
	Child1 *	c = dynamic_cast<Child1 *>(b);
	// it will either return the converted value or NULL
	if (c == NULL)
		std::cout << "Conversion is not ok\n";
	else
		std::cout << "Conversion is ok\n";

	// explict downcast (with reference) -> bad_cast
	try
	{
		Child2 &	d = dynamic_cast<Child2 &>(*b);
		// it will return a bad_cast exception if it fails (references can't be NULL)
		std::cout << "Conversion is ok\n";
	}
	catch(const std::bad_cast & e)
	{
		std::cout << "Conversion is not ok: " << e.what() << std::endl;
	}
}