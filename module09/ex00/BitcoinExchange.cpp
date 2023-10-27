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

// Exceptions
const char * BitcoinExchange::WrongDate::what() const throw()
{
	return "Error: bad input.";
}
const char * BitcoinExchange::NegativeNumber::what() const throw()
{
	return "Error: not a positive number.";
}
const char * BitcoinExchange::OutOfBondNumber::what() const throw()
{
	return "Error: number is out of bond.";
}

void BitcoinExchange::getPrice(std::string str) // add csv file
{
	// std::cout << str << std::endl;
	char *pEnd;
	errno = 0;
	long int year = strtol(str.c_str(), &pEnd, 10);
	// strtol sets errno to != 0 if out of bond. Since it's a long int, the out of bond is higher than for int. pEnd will be set to what remains after the conversion. if conversion was impossible. pEnd will be the inputed stirng.
	if (errno != 0 || year < INT_MIN || year > INT_MAX || pEnd[0] != '-')
		throw WrongDate();
	std::cout << year << std::endl;

	// to continue in the bus
	// should locate the lower closest date
	// should then set a variable to the value get in data.csv
	// (maybe compare the dates to get the right line?)
}

// Methods
void BitcoinExchange::getValue(char *fileName)
{
	std::ifstream	ifs(fileName);
	std::string		fileLine;

	// open csv and store it in a variable


	// get the file content if the file exist
	if (ifs.is_open()) {
		while (std::getline(ifs, fileLine)) {
			try {
				getPrice(fileLine);
			} catch (std::exception &e) {
    std::cout << e.what() << std::endl;
			}
		}
		ifs.close();
	}
	else {
		std::cout << "couldn't open file.. Are you sure the file exist?" << std::endl;
	}
}

