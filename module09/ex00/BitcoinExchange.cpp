#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void) copy;
}


// Destructor
BitcoinExchange::~BitcoinExchange()
{
}


// Operators
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void) assign;
	return *this;
}


// Methods
void BitcoinExchange::getValue(char *fileName)
{
	std::ifstream	ifs(fileName);
	std::string		fileLine;

	// get the file content if the file exist
	if (ifs.is_open()) {
		while (std::getline(ifs, fileLine)) {
			std::cout << fileLine << std::endl;
		}
		ifs.close();
	}
	else {
		std::cout << "couldn't open file.. Are you sure the file exist?" << std::endl;
	}
}

