#include "Span.hpp"

// Constructors
Span::Span() :	_n(0)
{
}

Span::Span(const Span &copy)
{
	_n = copy._n;
	_arr = copy._arr;
}

Span::Span(unsigned int N) : _n(N)
{
}


// Destructor
Span::~Span()
{
}


// Operators
Span & Span::operator=(const Span &assign)
{
	_n = assign._n;
	_arr = assign._arr;
	return *this;
}


// Exceptions
const char * Span::arrayIsFull::what() const throw()
{
	return "The array is full.";
}
const char * Span::notEnoughNumbers::what() const throw()
{
	return "There is not enough numbers in the array to find a span.";
}

// Methods
void Span::addNumber(int n) {
	// we use the >= operator because we don't add _arr size to _n size. to just use > we would then need to: (_arr.size() + 1 >= _n) (+1 being for the size of n)
	if (_arr.size() >= _n)
		throw Span::arrayIsFull();
	_arr.push_back(n);
}

void Span::addNumbers(std::vector<int> nums) {
	// we use the > operator because we add _arr size to nums size.
	if (_arr.size() + nums.size() > _n)
		throw Span::arrayIsFull();
	_arr.insert(_arr.end(), nums.begin(), nums.end());
}

int Span::shortestSpan() const {
	if (_arr.size() < 2)
		throw Span::notEnoughNumbers();
	std::vector<int> tmp = _arr;
	std::sort(tmp.begin(), tmp.end());
	int span = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < span)
			span = tmp[i] - tmp[i - 1];
	}
	return span;
}

int Span::longestSpan() const {
	if (_arr.size() < 2)
		throw Span::notEnoughNumbers();
	int min = *std::min_element(_arr.begin(), _arr.end());
	int max = *std::max_element(_arr.begin(), _arr.end());
	int span	= max - min;
	return span;
}
