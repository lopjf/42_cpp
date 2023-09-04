#include "Harl.hpp"

int main() {
	
	Harl harl;

	std::cout << std::endl << "Calling complain with: DEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "Calling complain with: INFO" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << "Calling complain with: WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "Calling complain with: ERROR" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "Calling complain with: heyy" << std::endl;
	harl.complain("heyy");

	return 0;
}