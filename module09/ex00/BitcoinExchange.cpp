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
const char * BitcoinExchange::NoFile::what() const throw()
{
	return "couldn't open file.. Are you sure the file exist?";
}
const char * BitcoinExchange::BadInput::what() const throw()
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
	char *pEnd;
	errno = 0;
	long int year = strtol(str.c_str(), &pEnd, 10);
	// strtol sets errno to != 0 if out of bond. Since it's a long int, the out of bond is higher than for int. pEnd will be set to what remains after the conversion. if conversion was impossible. pEnd will be the inputed stirng.
	if (errno != 0 || year < INT_MIN || year > INT_MAX || pEnd[0] != '-')
		throw BadInput();
	std::cout << "year: " << year << std::endl;
	pEnd++;

	long int month = strtol(pEnd, &pEnd, 10);
	if (errno != 0 || month < 1 || month > 12 || pEnd[0] != '-')
		throw BadInput();
	std::cout << "month: " << month << std::endl;
	pEnd++;

	long int day = strtol(pEnd, &pEnd, 10);
	if (errno != 0 || day < 1 || day > 31)
		throw BadInput();
	std::cout << "day: " << day << std::endl;

	if (strncmp(pEnd, " | ", 3) != 0)
		throw BadInput();
	pEnd += 3;

	// value could also be a float
	long int value = strtol(pEnd, &pEnd, 10);
	if (errno != 0 || value < 0 || value > 1000 || pEnd[0] != '\0')
		throw BadInput();
	std::cout << "value: " << value << std::endl;

	
	// should locate the lower closest date
	// maybe there is a way to work with dates. If so can check the date, if it's not in the database. get the date of the day before. etc

	// should then set a variable to the value get in data.csv
	// maybe a way to get the last digit of a vector?

	// (maybe compare the dates to get the right line?)
}

// Methods
void BitcoinExchange::getValue(char *fileName)
{
	std::ifstream				ifs1(fileName);
	std::ifstream				ifs2("data.csv");
	std::string					fileLine;
	std::vector<std::string>	csvContent;

	// open csv and store it in a variable
	try {
		if (!ifs2.is_open())
			throw NoFile();
		while (std::getline(ifs2, fileLine)) {
			csvContent.push_back(fileLine);
		}
		ifs2.close();
	} catch (std::exception &e) {
    	std::cout << e.what() << std::endl;
	}

	// get the file content if the file exist
	try {
		if (!ifs1.is_open())
			throw NoFile();
		while (std::getline(ifs1, fileLine)) {
			try {
				getPrice(fileLine);
			} catch (std::exception &e) {
    			std::cout << e.what() << std::endl;
			}
		}
		ifs1.close();
	} catch (std::exception &e) {
    	std::cout << e.what() << std::endl;
	}
}

