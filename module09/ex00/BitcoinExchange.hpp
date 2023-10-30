#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <limits.h>
#include <map>
#include <sstream>

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
		class NoFile : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class BadInput : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		// Methods
		// has to be static so we can call it from main without creating an instance of the class
		static void getValue(const char *fileName);
	private:

		static void getPrice(const std::string str, const std::map<std::string, float> csvContent);
		static std::string ft_itoa(const long int number);
		static float getClosestLowestValue(const std::map<std::string, float> &csvContent, const std::string inputDate);
};

#endif