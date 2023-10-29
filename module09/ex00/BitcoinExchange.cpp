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

std::string BitcoinExchange::ft_itoa(const long int number) {
	// this is sort of writing into a stream instead of in the terminal. Just like in minishell. We redirect it to catch it and that's how we convert int to string here.
	std::ostringstream oss;
	if (number <= 9 && number > 0)
		oss << 0;
	oss << number;
	return oss.str();
}

float BitcoinExchange::getClosestLowestValue(const std::map<std::string, float> &csvContent, const std::string inputDate) {

	// lower bond is using lexicographical comparison to get the value just before the one that is input.
	// it->first returns the key. it->second returns the value
	std::map<std::string, float>::const_iterator it = csvContent.lower_bound(inputDate);

	// If the exact date is found in the map
	if (it != csvContent.end() && it->first == inputDate) {
		return it->second;
	}

	// If the date is not found, but there is a lower date
	if (it != csvContent.begin()) {
		--it;	// go to the value before, it being an initialise value. it's skipping all the days to go straight to the closest value.
		return it->second;
	}

	// If the date is earlier than all dates in the map
	return it->second;
}

void BitcoinExchange::getPrice(const std::string str, const std::map<std::string, float> csvContent) // add csv file
{
	char *pEnd;
	errno = 0;
	long int year = strtol(str.c_str(), &pEnd, 10);
	// strtol sets errno to != 0 if out of bond. Since it's a long int, the out of bond is higher than for int. pEnd will be set to what remains after the conversion. if conversion was impossible. pEnd will be the inputed stirng.
	if (errno != 0 || year < INT_MIN || year > INT_MAX || pEnd[0] != '-')
		throw BadInput();
	pEnd++;

	long int month = strtol(pEnd, &pEnd, 10);
	if (errno != 0 || month < 1 || month > 12 || pEnd[0] != '-')
		throw BadInput();
	pEnd++;

	long int day = strtol(pEnd, &pEnd, 10);
	if (errno != 0 || day < 1 || day > 31)
		throw BadInput();

	if (strncmp(pEnd, " | ", 3) != 0)
		throw BadInput();
	pEnd += 3;

	double value = strtod(pEnd, &pEnd);;
	if (errno != 0 || value < 0 || value > 1000 || pEnd[0] != '\0')
		throw BadInput();


	std::string inputDate = ft_itoa(year) + std::string("-") + ft_itoa(month) + std::string("-") + ft_itoa(day);

	std::cout << inputDate << " => " << value << " = " << getClosestLowestValue(csvContent, inputDate) * value << std::endl;
}

// Methods
void BitcoinExchange::getValue(const char *fileName)
{
	std::ifstream																ifs1(fileName);
	std::ifstream																ifs2("data.csv");
	std::string																		fileLine;
	std::map<std::string, float>	csvContent;

	// open csv and store it in a variable
	try {
		if (!ifs2.is_open())
			throw NoFile();
		while (std::getline(ifs2, fileLine)) {
			std::string key(fileLine.substr(0, 10));
			float value = static_cast<float>(atof(fileLine.c_str() + 11));
			csvContent[key] = value;
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
				getPrice(fileLine, csvContent);
			} catch (std::exception &e) {
    std::cout << e.what() << std::endl;
			}
		}
		ifs1.close();
	} catch (std::exception &e) {
  std::cout << e.what() << std::endl;
	}
}

