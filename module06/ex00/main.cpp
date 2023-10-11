#include "ScalarConverter.hpp"

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

    ScalarConverter sc;
    sc.convert(std::string(av[1]));

    return (0);
}