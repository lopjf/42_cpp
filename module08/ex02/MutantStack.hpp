#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// Constructors
		MutantStack() {};

		MutantStack(const MutantStack &copy) {
			std::stack<T>::operator=(copy);
		};
		
		// Destructor
		~MutantStack(){};
		
		// Operators
		MutantStack & operator=(const MutantStack &assign) {
			std::stack<T>::operator=(assign);
			return (*this);
		};

		// Methods Iterators
/*
We can see both container_type and c on the stack cplusplus reference: https://en.cppreference.com/w/cpp/container/stack

In order to be able to get the proper return type of the begin() and end() methods we use:
1. the container_type member type of stack. which is available for any other container such as vector, list, stack etc.
We give it an alias cont for better readability.
2. From this container, we get the iterator methods. Available to all container_type.
and give it the iterator alias.

Then we create the two begin() and end() member functions:
We can call c. It is a member of a std::stack instance and is used to access the actual underlying container (an instance of container_type) stored within the stack.

container_type is used to create an alias for the underlying container type. c is used to access the specific instance of the underlying container stored within a std::stack object
*/

// Define an alias for the underlying container type of the stack
		typedef typename std::stack<T>::container_type cont;
// Define an alias for the iterator type associated with the underlying container
		typedef typename cont::iterator iterator;
		
// Define a custom begin() function that returns an iterator to the beginning of the stack's underlying container
		typename cont::iterator begin(void) {
			return std::stack<T>::c.begin();
		};
// Define a custom end() function that returns an iterator to the end of the stack's underlying container
		typename cont::iterator end(void) {
			return std::stack<T>::c.end();
		};
};

#endif