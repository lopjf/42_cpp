#include "PhoneBook.hpp"
#include "Contact.hpp"

int main() {
    PhoneBook phonebook;

    char buf[512];

    std::cout << "Available commands: ADD, SEARCH and EXIT" << std::endl;

    while (1) {
        std::cout << "Command: ";
        std::cin >> buf;

        if (strcmp(buf, "ADD\0") == 0)
            phonebook.add();
        else if (strcmp(buf, "SEARCH\0") == 0)
            phonebook.search();
        else if (strcmp(buf, "EXIT\0") == 0)
            return 0;
        else {
            std::cout << "Invalid command." << std::endl;
            std::cout << "Available commands: ADD, SEARCH and EXIT" << std::endl;
        }
    }
    return 0;
}
