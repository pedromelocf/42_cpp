#include "PhoneBook.hpp"
#include "Contact.hpp"

int main (void)
{
    std::string prompt;

    PhoneBook phonebook;

    while ( true ) 
    {
        std::cout << "Prompt your command: ADD, SEARCH or EXIT" << std::endl;
        std::getline ( std::cin, prompt );

        if ( !prompt.compare("ADD") )
            phonebook.AddContact();
        else if ( !prompt.compare("SEARCH") )
            phonebook.ShowPhoneBook();
        else if ( !prompt.compare("EXIT") || prompt.empty() )
            break;
    }

    return 0;
}
