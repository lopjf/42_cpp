#include <iostream>

// we can create template classes and struct
template<typename T>
class List
{
private:
	T *			_content;
	List<T> *	_next;

public:
	List<T>(T const & content);
	~List();
};

// we can use multiple typenames in the same template
template<typename T, typename U>
class Test
{
};

int main()
{
	// T can be int, char... or even another class
	List< int > a(42);
	// we have function parameters and type perameters
	List< float > b(4.2);
	List< List<int> > c(a);

	Test<char, double> t;
}