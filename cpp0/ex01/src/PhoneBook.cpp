#include "PhoneBook.hpp"

int PhoneBook::index = 0;

void PhoneBook::AddContact () {

    this->contact[index % 8].SetFirstName(GetInputForField(1));
    this->contact[index % 8].SetLastName(GetInputForField(2));
    this->contact[index % 8].SetNickName(GetInputForField(3));
    this->contact[index % 8].SetPhoneNumber(GetInputForField(4));
    this->contact[index % 8].SetDarkestSecret(GetInputForField(5));

    index += 1;

}

std::string GetInputForField ( int option ) {

    std::string prompt;

    switch ( option ) {
		case 1:
			std::cout << "  Define first name:   " ;
			break;

		case 2:
			std::cout << "   Define last name:   " ;
			break;
		
		case 3:
			std::cout << "   Define nickname:    " ;
			break;

		case 4:
			std::cout << " Define phone number:  " ;
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

	return ( "Error" ) ;
	
}

void PhoneBook::ShowPhoneBook () {

    int index = 0;
    int size = GetPhoneBookSize();

	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;

    while (index < size)
    {
        std::cout << "|         " << index + 1 << "|" ;
        std::cout << RightAlignAndTruncate( this->contact[index].GetFirstName() ) ;
        std::cout << RightAlignAndTruncate( this->contact[index].GetLastName() ) ;
        std::cout << RightAlignAndTruncate( this->contact[index].GetNickName() ) ;
        std::cout << std::endl;
        index++;
    }
    
    this->SearchContactInterface();

}

std::string RightAlignAndTruncate (std::string to_format) {

	std::string formated;

	if ( to_format.length() >= 10 ) {
		formated = to_format.substr( 0, 9 );
		formated.append( "." );
	}
	else {
		formated.append( 10 - to_format.length() , ' ' );
		formated.append( to_format );
	}
	formated.append( "|" );
	return (formated);

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
        std::cout << "Invalid index" << std::endl;
    else
    {
        std::cout << "First Name:     " << this->contact[index - 1].GetFirstName() << std::endl ;
        std::cout << "Last Name:      " << this->contact[index - 1].GetLastName() << std::endl ;
        std::cout << "NickName:       " << this->contact[index - 1].GetNickName() << std::endl ;
        std::cout << "Phone Number:   " << this->contact[index - 1].GetPhoneNumber() << std::endl ;
        std::cout << "Darkest Secret: " << this->contact[index - 1].GetDarkestSecret() << std::endl ;
    }
}

int PhoneBook::GetPhoneBookSize () {

    int size = 0;

    while ( size < 8 && !this->contact[size].GetFirstName().empty() )
        size++;
    return ( size );

}
