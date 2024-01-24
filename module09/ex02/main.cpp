#include <iostream>
#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    if (ac < 2) {
        std::cout << "The program must take at least 1 argument." << std::endl;
        return 1;
    }
    PmergeMe::sort(ac, av);
    return 0;
}
