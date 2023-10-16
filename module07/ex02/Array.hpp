#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template <typename T>
class Array
{
	public:
		// Constructors
		Array();
		Array(int n);
		Array(const Array &copy);
		
		// Destructor
		~Array();
		
		// Operators
		Array & operator=(const Array &assign);
		// Overloading [] operator to access elements in array style
    	T & operator[](int i);
		
		// Methods
		int size() const;

		// Exceptions
		class OutOfBond : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		
		T *_arr;
		int _size;

};

#endif