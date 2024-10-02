#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {

    private: 

        Contact contact[8];

    public:
    
        void AddContact();
        Contact SearchContact();

};

#endif