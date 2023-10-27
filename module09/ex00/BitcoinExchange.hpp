#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <limits.h>

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		
		// Destructor
		~BitcoinExchange();
		
		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);
		
		// Exceptions
		class WrongDate : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NegativeNumber : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class OutOfBondNumber : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		// Methods
		// has to be static so we can call it from main without creating an instance of the class
		static void getValue(char *fileName);
	private:

		static void getPrice(std::string str);
		
};

#endif