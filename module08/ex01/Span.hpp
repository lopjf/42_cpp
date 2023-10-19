#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Span
{
	public:
		// Constructors
		Span();
		Span(const Span &copy);
		Span(unsigned int N);
		
		// Destructor
		~Span();
		
		// Operators
		Span & operator=(const Span &assign);
		
		// Exceptions
		class arrayIsFull : public std::exception {
			virtual const char* what() const throw();
		};
		class notEnoughNumbers : public std::exception {
			virtual const char* what() const throw();
		};

		// Methods
		void addNumber(int n);
		void addNumbers(std::vector<int> nums);
		int shortestSpan() const;
		int longestSpan() const;
		
	private:
	// https://cplusplus.com/reference/vector/vector/
	// Compared to the other dynamic sequence containers (deques, lists and forward_lists), vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end. For operations that involve inserting or removing elements at positions other than the end, they perform worse than the others, and have less consistent iterators and references than lists and forward_lists.
		std::vector<int> _arr;
		unsigned int _n;
		
};

#endif