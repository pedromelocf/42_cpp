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
            std::cout << "PROMPT: ADD" << std::endl;
        else if ( !prompt.compare("SEARCH") )
            std::cout << "PROMPT: SEARCH" << std::endl;
        else if ( !prompt.compare("EXIT") || prompt.empty() )
            break;
    }

    return 0;
}
