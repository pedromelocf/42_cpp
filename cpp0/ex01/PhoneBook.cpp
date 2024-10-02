#include "PhoneBook.hpp"

void PhoneBook::AddContact () {

    int size = GetPhoneBookSize();

    if ( size == 8 )
        size -= 1;

    this->contact[size].SetFirstName(GetInputForField(1));
    this->contact[size].SetLastName(GetInputForField(2));
    this->contact[size].SetNickName(GetInputForField(3));
    this->contact[size].SetPhoneNumber(GetInputForField(4));
    this->contact[size].SetDarkestSecret(GetInputForField(5));

}

static std::string GetInputForField ( int option ) {

    std::string prompt;

    switch ( option ) {
		case 1:
			std::cout << "Define first name: " ;
			break;

		case 2:
			std::cout << "Define last name: " ;
			break;
		
		case 3:
			std::cout << "Define nick name: " ;
			break;

		case 4:
			std::cout << "Define phone number: " ;
			break;

		case 5:
			std::cout << "Define darkest secret: " ; 
			break;
    }

	while ( std::getline ( std::cin , prompt ) )
	{
		if ( !prompt.empty() )
			return ( prompt ) ;
		std::cout << "Field cannot be empty! Fill it again: " ;
	}

}

void PhoneBook::ShowPhoneBook () {

    int index = 0;
    int size = GetPhoneBookSize();

    while (index < size)
    {
        std::cout << index + 1 << "|" ;
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

    if ( index > 8 || index < 1 || this->contact[index - 1].GetFirstName().empty() )
        std::cout << "Invalid range" << std::endl;
    else
    {
        std::cout << this->contact[index - 1].GetFirstName() << std::endl ;
        std::cout << this->contact[index - 1].GetLastName() << std::endl ;
        std::cout << this->contact[index - 1].GetNickName() << std::endl ;
        std::cout << this->contact[index - 1].GetPhoneNumber() << std::endl ;
        std::cout << this->contact[index - 1].GetDarkestSecret() << std::endl ;
    }
}

int PhoneBook::GetPhoneBookSize () {

    int size = 0;

    while ( size < 8 && !this->contact[size].GetFirstName().empty() )
        size++;
    return ( size );

}
