#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include "Contact.hpp"

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {
    
public:

    PhoneBook();
    ~PhoneBook(void);

    void add(void);
    void search(void) const;

private:

    Contact contacts[8];

};


#endif