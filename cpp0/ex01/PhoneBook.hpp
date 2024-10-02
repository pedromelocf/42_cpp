#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook {

    private: 

        Contact contact[8];

    public:
    
        void AddContact ();
        void ShowPhoneBook ();
        void SearchContactInterface ();
        void SearchContactByIndex ( std::string prompt );
        int GetPhoneBookSize ();

};

#endif