#include "Harl.hpp"

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		std::cout << "Wrong number of argument. harlFilter takes 1 argument." << std::endl;
		return 0;
	}
	
	Harl harl;

	int i = 0;

	if (std::strcmp(argv[1], "DEBUG") == 0)
		i = 1;
	if (std::strcmp(argv[1], "INFO") == 0)
		i = 2;
	if (std::strcmp(argv[1], "WARNING") == 0)
		i = 3;
	if (std::strcmp(argv[1], "ERROR") == 0)
		i = 4;

	switch(i) {
		case 1:
			harl.complain("DEBUG");
		case 2:
			harl.complain("INFO");
		case 3:
			harl.complain("WARNING");
		case 4:
			harl.complain("ERROR");
			break;
		default:
			harl.complain("ok");
	}

	return 0;
}