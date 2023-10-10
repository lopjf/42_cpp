int main()
{
	int			a = 42;							// reference value

	// usually if you have to use const_cast, your code is wrong

	int const *	b = &a;							// implicit promotion -> Ok
//	int *		c = b;							// implicit demotion -> does not compile
	int *		d = const_cast<int *>(b);		// implicit demotion -> Ok, I obey
}