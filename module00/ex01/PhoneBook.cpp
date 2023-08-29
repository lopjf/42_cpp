#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::search(void) {
    if (this->contacts[0].index == 0) {
        std::cout << "No contact to display" << std::endl;
        return;
    }

    std::cout << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << std::right << "first name" << "|";
    std::cout << std::setw(10) << std::right << "last name" << "|";
    std::cout << std::setw(10) << std::right << "nickname";
    std::cout << std::endl;

    for (int i = 0; i < 8; i++) {
        if (this->contacts[i].index == 0)
            break;
        std::cout << std::setw(10) << std::right << this->contacts[i].index << "|";
        std::cout << std::setw(10) << std::right << (this->contacts[i].firstName.length() > 10 ? contacts[i].firstName.substr(0, 9) + "." : contacts[i].firstName) << "|";
        std::cout << std::setw(10) << std::right << (this->contacts[i].lastName.length() > 10 ? contacts[i].lastName.substr(0, 9) + "." : contacts[i].lastName) << "|";
        std::cout << std::setw(10) << std::right << (this->contacts[i].nickname.length() > 10 ? contacts[i].nickname.substr(0, 9) + "." : contacts[i].nickname);
        std::cout << std::endl;
    }

    std::string buf;
    std::cout << "Select index: ";
    std::getline(std::cin, buf);
    int idx = std::atoi(buf.c_str()) - 1;

    if (idx > -1 && idx < 8) {
        if (this->contacts[idx].firstName.empty())
            std::cout << "Contact doesn't exist" << std::endl;
        else {
            std::cout << "first name: " + this->contacts[idx].firstName << std::endl;
            std::cout << "last name: " + this->contacts[idx].lastName << std::endl;
            std::cout << "nickname: " + this->contacts[idx].nickname << std::endl;
            std::cout << "phone number: " + this->contacts[idx].phoneNumber << std::endl;
            std::cout << "darkest secret: " + this->contacts[idx].darkestSecret << std::endl;
        }
    }
    else
        std::cout << "Incorrect index" << std::endl;

}

void PhoneBook::add(void) {

    static int i = -1;
    i++;

    std::string p1;
    std::string p2;
    std::string p3;
    std::string p4;
    std::string p5;

    while (p1.empty())
        std::cout << "first name: ", std::getline (std::cin, p1);
    while (p2.empty())
        std::cout << "last name: ", std::getline (std::cin, p2);
    while (p3.empty())
        std::cout << "nickname: ", std::getline (std::cin, p3);
    while (p4.empty())
        std::cout << "phone number: ", std::getline (std::cin, p4);
    while (p5.empty())
        std::cout << "darkest secret: ", std::getline (std::cin, p5);

    this->contacts[i % 8].index = (i % 8) + 1;
    this->contacts[i % 8].firstName = p1;
    this->contacts[i % 8].lastName = p2;
    this->contacts[i % 8].nickname = p3;
    this->contacts[i % 8].phoneNumber = p4;
    this->contacts[i % 8].darkestSecret = p5;
}

PhoneBook::PhoneBook() {

    return;
}

PhoneBook::~PhoneBook(void) {

    return;
}
