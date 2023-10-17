#include <iostream>
#include <iomanip>

template< typename T, typename U >
class Pair
{
private:
	T const & _lhs;
	U const & _rhs;
	Pair();

public:
	Pair<T, U>(T const & lhs, U const & rhs) : _lhs(lhs), _rhs(rhs) {
		std::cout << "generic template" << std::endl;
	}
	
	T const & get1() const { return _lhs; }
	U const & get2() const { return _rhs; }

};

// partial specialization (we have to create another class)
template< typename U >
// specify the types in the class declaration
class Pair< int, U >
{
private:
	int const & _lhs;
	U const & _rhs;
	Pair();

public:
	Pair<int, U>(int const & lhs, U const & rhs) : _lhs(lhs), _rhs(rhs) {
		std::cout << "int partial specialization" << std::endl;
	}
	
	int const & get1() const { return _lhs; }
	U const & get2() const { return _rhs; }

};

// full template specialization
template< >
class Pair <bool, bool>
{
private:
	int _n;
	Pair();

public:
	//vscode gives error but code compiles ?
	Pair<bool, bool>(bool lhs, bool rhs) 	
	{
		std::cout << "bool/bool template" << std::endl;
		_n = 0;
		// we use first 2 bits of _n to store 2 booleans
		_n |= static_cast<int>(lhs) << 0; // bit switch
		_n |= static_cast<int>(rhs) << 1;
	}
	
	bool get1() const { return (_n & 0x01); }
	bool get2() const { return (_n & 0x02); }

};

template< typename T, typename U >
std::ostream & operator << (std::ostream & o, Pair< T , U > const & rhs)
{
	o << rhs.get1() << " " << rhs.get2();
	return o;
}

// specialized overload
std::ostream & operator << (std::ostream & o, Pair< bool, bool > const & rhs)
{
	o << std::boolalpha << rhs.get1() << " " << rhs.get2();
	return o;
}

int main()
{
	Pair<char, bool> a('a', true);
	Pair<int , double> b(12, 5.5);
	Pair<bool, bool> c(true, false);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;


}