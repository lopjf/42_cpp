#include "RPN.hpp"

int main(int ac, char *av[])
{
    // website to play around: https://www.dcode.fr/reverse-polish-notation
    if (ac != 2) {
        std::cout << "The program must take 1 argument." << std::endl;
        return 1;
    }
    try {
        RPN::processRpn(av[1]);
	} catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	}
    return 0;
}
