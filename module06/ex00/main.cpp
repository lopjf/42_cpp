#include "ScalarConverter.hpp"

class ScalarConverter;

int	main(int ac, char **av)
{
	if (ac < 2)
    {
        std::cout << "No argument provided." << std::endl;
        return (1);
    } else if (ac > 2) {
        std::cout << "Too many arguments provided." << std::endl;
        return (1);
    }

    ScalarConverter::convert(std::string(av[1]));

    return (0);
}