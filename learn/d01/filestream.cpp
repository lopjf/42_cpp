#include <iostream>
#include <fstream>

// https://cplusplus.com/doc/tutorial/files/

int main() {

	std::ifstream	ifs("numbers");
	unsigned int	dst;
	unsigned int	dst2;
	ifs >> dst >> dst2;

	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();



	std::ofstream	ofs("test.out");

	ofs << "i like ponies" << std::endl;
	ofs.close();
	return 0;
}