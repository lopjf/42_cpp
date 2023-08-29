#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {
    
public:

    PhoneBook();
    ~PhoneBook(void);

    void add(void);
    void search(void);

private:

    Contact contacts[8];

};


#endif