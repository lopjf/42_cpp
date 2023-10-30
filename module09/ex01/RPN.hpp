#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
// stack is Last-In, First-Out (LIFO). Most efficient for the tasks we need to do in this exercice.
#include <cstdlib>
#include <cctype>
class RPN
{
	public:
		// Constructors
		RPN();
		RPN(const RPN &copy);
		
		// Destructor
		~RPN();
		
		// Operators
		RPN & operator=(const RPN &assign);
		
		// exceptions
		class Error : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		// Methods
		static void processRpn(char *str);

	private:
		static void skipSpaces(char *&str);
		static bool checkChar(const char c, std::stack<long int> numbers);
};

#endif