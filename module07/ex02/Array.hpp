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
		Array(uint n);
		Array(const Array &copy);
		
		// Destructor
		~Array();
		
		// Operators
		Array & operator=(const Array &assign);
		// Overloading [] operator to access elements in array style
    	T & operator[](long i);
		
		// Methods
		uint size() const;

		// Exceptions
		class OutOfBond : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		
		T *_arr;
		uint _size;

};

#endif