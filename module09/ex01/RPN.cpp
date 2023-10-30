#include "RPN.hpp"

// Constructors
RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	(void) copy;
}


// Destructor
RPN::~RPN()
{
}


// Operators
RPN & RPN::operator=(const RPN &assign)
{
	(void) assign;
	return *this;
}


// Exceptions
const char * RPN::Error::what() const throw()
{
	return "Error";
}

void RPN::skipSpaces(char *&str) {
	while (*str == ' ' && *str)
		str++;
}

bool RPN::checkChar(const char c, std::stack<long int> numbers) {
// we first only check the isdigit because the first char can only be a digit
	if ((c == '+' || c == '-' || c == '/' || c == '*') && numbers.size() < 2)
		return false;
	if (isdigit(c) || c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

// Methods
void RPN::processRpn(char *str) {

	std::stack<long int> numbers;
	long int tmp1;
	long int tmp2;


	while (1) {
		skipSpaces(str);

		if (!checkChar(str[0], numbers))
			throw Error();

		if (isdigit(str[0]))
			numbers.push(str[0] - 48);
		else {
			if (numbers.size() < 2)
				throw Error();
			tmp2 = numbers.top();
			numbers.pop();
			tmp1 = numbers.top();
			numbers.pop();
			if (str[0] == '+') {
				numbers.push(tmp1 + tmp2);
			} else if (str[0] == '-') {
				numbers.push(tmp1 - tmp2);
			} else if (str[0] == '/') {
				numbers.push(tmp1 / tmp2);
			} else if (str[0] == '*') {
				numbers.push(tmp1 * tmp2);
			}
		}


		str++;
		skipSpaces(str);
		if (!*str) // if (str[0] == '\0')
			break;
	}
	if (numbers.size() != 1)
		throw Error();
	std::cout << numbers.top() << std::endl;
}

