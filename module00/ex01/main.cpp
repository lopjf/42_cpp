#include "PhoneBook.hpp"
#include "Contact.hpp"

int main() {
    PhoneBook phonebook;

    std::string buf;

    std::cout << "Available commands: ADD, SEARCH and EXIT" << std::endl;

    while (1) {
        std::cout << "Command: ";
        while (!(std::getline(std::cin, buf)))
			return 0;

        if (buf.compare("ADD") == 0)
            phonebook.add();
        else if (buf.compare("SEARCH") == 0)
            phonebook.search();
        else if (buf.compare("EXIT") == 0)
            return 0;
        else {
            std::cout << "Invalid command " << std::endl;
            std::cout << "Available commands: ADD, SEARCH and EXIT" << std::endl;
        }
    }
    return 0;
}
