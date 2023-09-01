#include <iostream>
#include <fstream>
#include <cstring>

// https://cplusplus.com/doc/tutorial/files/

void	replace_string(std::string str, char *s1, char *s2) {
	int j = 0;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == s1[j]) {
			i++;
			j++;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Program takes 3 arguments. A filename and two strings." << std::endl;
		return 0;
	}

	std::ifstream	ifs(argv[1]);
	std::string		fileLine;
	std::string		fileContent;

	// get the file content if the file exist
	if (ifs.is_open()) {
		while (std::getline(ifs, fileLine)) {
			fileContent.append(fileLine + "\n");
		}
		ifs.close();
	}
	else {
		std::cout << "couldn't open file.." << std::endl;
		return 0;
	}
	// std::cout << fileContent << std::endl;

	replace_string(fileContent, argv[2], argv[3]);

	// create the .replace version and copy the updated fileContent
	char	*ofsName = argv[1];
	strcat(ofsName, ".replace");
	std::ofstream	ofs(ofsName);

	ofs << fileContent << std::endl;
	ofs.close();
	return 0;
}

/*
std::ifstream ifs("example.txt");
This uses the constructor of std::ifstream to open the file "example.txt" during object initialization.

std::ifstream myfile;
myfile.open("example.txt");
This declares an std::ifstream object named myfile and then opens the file "example.txt" using the open method of the std::ifstream class.
*/