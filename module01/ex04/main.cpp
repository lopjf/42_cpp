#include <iostream>
#include <fstream>
#include <cstring>

// https://cplusplus.com/doc/tutorial/files/



std::string	replace_string(std::string str, const char *s1, const char *s2) {
	std::string ret = str;

	for (unsigned long i = 0; i < ret.length(); i++) {
		if (ret[i] == s1[0]) {
			if (std::strncmp(&ret[i], s1, strlen(s1)) == 0) {
				ret.erase(i, strlen(s1));
				ret.insert(i, s2, strlen(s2));
				i += strlen(s2) - 1;
			}
		}
	}
	return ret;
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
		fileContent.resize(fileContent.length() - 1);
	}
	else {
		std::cout << "couldn't open file.." << std::endl;
		return 0;
	}

	fileContent = replace_string(fileContent, argv[2], argv[3]);

	// create the .replace version and copy the updated fileContent
	char	*ofsName = argv[1];
	strcat(ofsName, ".replace");
	std::ofstream	ofs(ofsName);

	ofs << fileContent;
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