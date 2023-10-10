class Parent {};

class Child1 : public Parent {};
class Child2 : public Parent {};

// casting within class hierarchy
// childs are more accurate (more specialized) versions of parent
int main()
{
	Child1		a;						// reference value

	Parent *	b = &a;					// implicit "reinterpretation" cast
	Parent *	c = (Parent *)&a;		// explicit "reinterpretation" cast

	Parent *	d = &a;					// implict upcast -> Ok
//	Child1 *	e = d;					// implict downcast -> Compile error	
	Child2 *	f = (Child2 *)d;		// explict downcast -> Ok, but really?
}