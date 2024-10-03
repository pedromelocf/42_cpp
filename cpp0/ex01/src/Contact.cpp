#include "Contact.hpp"

void Contact::SetFirstName (std::string fn) {
    this->firstname = fn;
}

void Contact::SetLastName (std::string ln) {
    this->lastname = ln;
}

void Contact::SetNickName (std::string nn) {
    this->nickname = nn;
}

void Contact::SetPhoneNumber (std::string pn) {
    this->phonenumber = pn;
}

void Contact::SetDarkestSecret (std::string ds) {
    this->darkestsecret = ds;
}

std::string Contact::GetFirstName () {
    return ( this->firstname );
}

std::string Contact::GetLastName () {
    return ( this->lastname );
} 

std::string Contact::GetNickName () {
    return ( this->nickname );
}

std::string Contact::GetPhoneNumber () {
    return ( this->phonenumber );
}

std::string Contact::GetDarkestSecret () {
    return ( this->darkestsecret );
}
