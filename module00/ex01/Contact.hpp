#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cctype>

#ifndef CONTACT_H
# define CONTACT_H

class Contact {
    
public:

    Contact();
    ~Contact(void);

    int         index;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

};


#endif