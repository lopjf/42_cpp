#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    if (ac != 2) {
        std::cout << "The program takes 1 argument." << std::endl;
        return 1;
    }
    BitcoinExchange::getValue(av[1]);
    return 0;
}
