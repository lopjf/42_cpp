#include <iostream>
#include <cstring>
#include "Contact.hpp"

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {
    
public:

    Contact contacts[8];

    PhoneBook();
    ~PhoneBook(void);

    int add(void);
    void search(void);

private:

    void prompt(int);

};


#endif