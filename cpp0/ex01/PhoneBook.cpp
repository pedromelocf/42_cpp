#include "PhoneBook.hpp"

void PhoneBook::AddContact () {

    int size = GetPhoneBookSize();

    if ( size == 8 )
        size -= 1;
        
    this->contact[size].SetFirstName("Pedro");
    this->contact[size].SetLastName("Melo");
    this->contact[size].SetNickName("Pedin");
    this->contact[size].SetPhoneNumber("+55 83 99656-8104");
    this->contact[size].SetDarkestSecret("I am you!");

}

void PhoneBook::ShowPhoneBook () {

    int index = 0;
    int size = GetPhoneBookSize();

    while (index < size)
    {
        std::cout << index << "|" ;
        std::cout << this->contact[index].GetFirstName() << "|";
        std::cout << this->contact[index].GetLastName() << "|";
        std::cout << this->contact[index].GetNickName() << "|";
        std::cout << std::endl;
        index++;
    }
    
    this->SearchContactInterface();

}

void PhoneBook::SearchContactInterface () {
    
    std::string prompt;

    std::cout << "Prompt the index of the entry to display:" << std::endl;
    std::getline ( std::cin , prompt );
    SearchContactByIndex ( prompt );

}

void PhoneBook::SearchContactByIndex ( std::string prompt ) {

    int index = atoi( prompt.c_str() );

    if ( index > 7 || index < 0 || this->contact[index].GetFirstName().empty() )
        std::cout << "Invalid range" << std::endl;
    else
    {
        std::cout << this->contact[index].GetFirstName() << std::endl ;
        std::cout << this->contact[index].GetLastName() << std::endl ;
        std::cout << this->contact[index].GetNickName() << std::endl ;
        std::cout << this->contact[index].GetPhoneNumber() << std::endl ;
        std::cout << this->contact[index].GetDarkestSecret() << std::endl ;
    }
}

int PhoneBook::GetPhoneBookSize () {

    int size = 0;

    while ( size < 8 && !this->contact[size].GetFirstName().empty() )
        size++;
    return ( size );

}
