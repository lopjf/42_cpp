#include "Harl.hpp"

int main() {
	
	Harl harl;

	std::cout << std::endl << "Calling complain with: heyy" << std::endl;
	harl.complain("heyy");
	std::cout << std::endl << "Calling complain with: debug" << std::endl;
	harl.complain("debug");
	std::cout << std::endl << "Calling complain with: info" << std::endl;
	harl.complain("info");
	std::cout << std::endl << "Calling complain with: warning" << std::endl;
	harl.complain("warning");
	std::cout << std::endl << "Calling complain with: error" << std::endl;
	harl.complain("error");

	return 0;
}