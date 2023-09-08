#include "Harl.hpp"

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		std::cout << "Wrong number of argument. harlFilter takes 1 argument." << std::endl;
		return 0;
	}
	
	Harl harl;

	harl.complain(argv[1]);

	return 0;
}