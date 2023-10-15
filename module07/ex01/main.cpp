#include "iter.hpp"

void increment_all(int i) {
	i++;
	std::cout << "i: " << i << std::endl;
}

void print_str(std::string str) {
	std::cout << "str: " << str << std::endl;
}

int	main(void)
{
	int array_int[4] = {-42, 0, 42, 90};
	int len_int = 4;

	iter(array_int, len_int, increment_all);


	std::cout << std::endl << "------------" << std::endl << std::endl;


	std::string array_str[3] = {"Hello", "42", "peeps!"};
	int len_str = 3;

	iter(array_str, len_str, print_str);

	return (0);
}