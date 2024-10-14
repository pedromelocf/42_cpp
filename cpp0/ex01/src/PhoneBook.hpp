#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

std::string GetInputForField ( int option );
std::string RightAlignAndTruncate (std::string to_format);

class PhoneBook {

    private: 

        Contact contact[8];
        static int index;

    public:
    
        void AddContact ();
        void ShowPhoneBook ();
        void SearchContactInterface ();
        void SearchContactByIndex ( std::string prompt );
        int GetPhoneBookSize ();
    
};

#endif