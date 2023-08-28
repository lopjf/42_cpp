#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::search(void) {
    if (this->contacts[0].index == 42) {
        std::cout << "No contact to display" << std::endl;
        return;
    }

    std::cout << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << std::right << "first name" << "|";
    std::cout << std::setw(10) << std::right << "last name" << "|";
    std::cout << std::setw(10) << std::right << "nickname";
    std::cout << std::endl;
    for (int i = 0; i < 8; i++) {
        if (this->contacts[i].index == 42)
            break;
        std::cout << std::setw(10) << std::right << this->contacts[i].index << "|";
        std::cout << std::setw(10) << std::right << (this->contacts[i].firstName.length() > 10 ? contacts[i].firstName.substr(0, 9) + "." : contacts[i].firstName) << "|";
        std::cout << std::setw(10) << std::right << (this->contacts[i].lastName.length() > 10 ? contacts[i].lastName.substr(0, 9) + "." : contacts[i].lastName) << "|";
        std::cout << std::setw(10) << std::right << (this->contacts[i].nickname.length() > 10 ? contacts[i].nickname.substr(0, 9) + "." : contacts[i].nickname);
        std::cout << std::endl;
    }

}

void PhoneBook::prompt(int i) {
    std::string p1;
    std::string p2;
    std::string p3;
    std::string p4;
    std::string p5;

    std::cin.ignore();
    std::cout << "first name: ";
    std::getline (std::cin, p1);
    std::cout << "last name: ";
    std::getline (std::cin, p2);
    std::cout << "nickname: ";
    std::getline (std::cin, p3);
    std::cout << "phone number: ";
    std::getline (std::cin, p4);
    std::cout << "darkest secret: ";
    std::getline (std::cin, p5);

    this->contacts[i].index = i;
    this->contacts[i].firstName = p1;
    this->contacts[i].lastName = p2;
    this->contacts[i].nickname = p3;
    this->contacts[i].phoneNumber = p4;
    this->contacts[i].darkestSecret = p5;

}

int PhoneBook::add(void) {

    static int tracker = -1;
    tracker++;
    prompt(tracker % 8);

    return 0;
}

PhoneBook::PhoneBook() {

    return;
}

PhoneBook::~PhoneBook(void) {

    return;
}
