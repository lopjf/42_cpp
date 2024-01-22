#include "Array.hpp"

// Since you are working with a class template Array, you need to specify the template arguments when using it in your implementation file (.tpp) as follows:

// Specifying template arguments is necessary because you're working with a class template. Class templates in C++ are parameterized by a data type or a set of data types, and in order to use them, you need to provide specific data types as arguments when creating instances or defining member functions.

// Here's why you should specify template arguments:

// Data Type Flexibility: Class templates allow you to create classes that can work with different data types without having to rewrite the class for each type. By specifying the template arguments, you define the actual data type(s) that the class template will work with. This provides flexibility and reusability.

// Compilation: The compiler needs to know the specific data type you intend to use with the class template to generate the correct code. If you don't specify the template arguments, the compiler won't know how to instantiate the template, leading to compilation errors.

// Type Safety: Specifying the data type provides type safety. It ensures that you're using the class template with appropriate data types, reducing the risk of type-related errors.

// Code Clarity: When someone reads your code, specifying the template arguments makes it clear what data types the class is intended to work with. It improves code readability and maintainability.

// Constructors
template <typename T>
Array<T>::Array()
{
	_arr = new T[0];
	_size = 0;
	std::cout << "\e[0;33mConstructor called of Array\e[0m" << std::endl;
}

template <typename T>
Array<T>::Array(uint n)
{
	_arr = new T[n];
	_size = n;
	std::cout << "\e[0;33mConstructor parameter uint n called of Array\e[0m" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
	uint n = copy.size();
	_size = n;

	_arr = new T[_size];
	for (uint i = 0; i < _size; i++) {
		_arr[i] = copy._arr[i];
	}
	std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
}


// Destructor
template <typename T>
Array<T>::~Array()
{
	delete [] _arr;
	std::cout << "\e[0;31mDestructor called of Array\e[0m" << std::endl;
}


// Exceptions
template <typename T>
const char * Array<T>::OutOfBond::what() const throw()
{
	return "Array index out of bound!";
}


// Operators
template <typename T>
Array<T> & Array<T>::operator=(const Array<T> &assign)
{
	uint n = assign.size();
	_size = n;

	delete [] _arr;
	_arr = new T[_size];
	for (uint i = 0; i < _size; i++) {
		_arr[i] = assign._arr[i];
	}
	std::cout << "\e[0;33mAssignment operator called of Array\e[0m" << std::endl;
	return *this;
}

// Implementation of [] operator.  This function must return a
// reference as array element can be put on left side
template <typename T>
T & Array<T>::operator[](long i)
{
	if (i < 0 || i >= size()) {
		throw Array<T>::OutOfBond();
	}
    return _arr[i];
}


// Methods
template <typename T>
uint Array<T>::size() const
{
	return _size;
}
