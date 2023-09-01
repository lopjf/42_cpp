#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        for (int i = 1; i < argc; i++) {
            for (size_t j = 0; j < std::strlen(argv[i]); j++) {
                if (argv[i][j] >= 97 && argv[i][j] <= 122)
                    argv[i][j] -= 32;
            }
            std::cout << argv[i];
        }
        std::cout << std::endl;
    }

    return (0);
}   