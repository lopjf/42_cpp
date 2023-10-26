#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
#include <fstream>

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
		
		// Methods
		// has to be static so we can call it from main without creating an instance of the class
		static void getValue(char *fileName);
	private:
		
};

#endif