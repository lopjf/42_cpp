int main()
{
	int		a = 42;						// reference value

	double	b = a;						// implicit promotion -> Ok
	int		c = b;						// implicit demotion -> Hell no
	int		d = static_cast<int>(b);	// explicit demotion -> Ok i obey

}