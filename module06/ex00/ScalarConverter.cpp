#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
	std::cout << "Copy constructor called" << std::endl;
}


// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return *this;
}


bool isNumber(const std::string str) {
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (std::isdigit(str[i]) == 0 && str[i] != '.' && str[i] != 'f')
			return false;
	}
	return true;
}

// Methods
void ScalarConverter::convert(std::string str)
{

	char *pEnd = NULL;
	long double tmp;
	char	cha;
	int		num;
	float	flo;
	double	dou;

	float	minF = std::numeric_limits<float>::max() * -1;
	double	minD = std::numeric_limits<double>::max() * -1;

	tmp = strtod(&str[0], &pEnd);

	if ((pEnd[0] != '\0' && pEnd[1] != '\0') || (pEnd[0] != 'f' && pEnd[1] == '\0' && tmp != 0) || str == "inff" || str == "inf") {
		std::cout << "Invalid Parameter" << std::endl;
		return ;
	}

	if (str == "nan" || str == "nanf" || str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff") {
		dou = tmp;
		flo = static_cast<float>(tmp);

		std::cout << "char: Impossible!" << std::endl;
		std::cout << "int: Impossible!" << std::endl;
		std::cout << "float: " << flo << 'f' << std::endl;
		std::cout << "double: " << dou << std::endl;
		return ;
	}

	// CHAR
	if (!(isNumber(str) || (str[0] == '-' && isNumber(&str[1])))) {
		tmp = static_cast<double>(pEnd[0]);
		std::cout << "char: '" << pEnd[0] << "'"<< std::endl;
	}
	else {
		cha = static_cast<char>(tmp);
		if (isprint(cha))
			std::cout << "char: '" << cha << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	// INT
	if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min()) {
		std::cout << "int: impossible" << std::endl;
	}
	else {
		num = static_cast<int>(tmp);
		std::cout << "int: " << num << std::endl;
	}
	// FLOAT
	if (tmp > std::numeric_limits<float>::max() || tmp < minF)
		std::cout << "float: impossible" << std::endl;
	else {
		flo = static_cast<float>(tmp);	// precision loss is expected
		std::cout << "float: " << std::fixed << std::setprecision(1) << flo << "f" << std::endl;
	}
	// DOUBLE
	if (tmp > std::numeric_limits<double>::max() || tmp < minD)
		std::cout << "double: impossible" << std::endl;
	else {
		dou = static_cast<double>(tmp);
		std::cout << "double: " << std::fixed << std::setprecision(1) << dou << std::endl;
	}
}
