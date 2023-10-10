class Parent {};

class Child1 : public Parent {};
class Child2 : public Parent {};

class Unrelated {};

int main()
{
	Child1		a;									// reference value

	Parent *	b = &a;								// implict upcast -> Ok
//	Child1 *	c = b;								// implict downcast -> compile error
	Child2 *	d = static_cast<Child2 *>(b);		// explict downcast -> Ok, I obey

//	Unrelated *	e = static_cast<Unrelated *>(&a);	// explict conversion -> invalid conversion (not related)
}