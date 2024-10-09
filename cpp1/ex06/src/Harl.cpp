#include "Harl.hpp"

Harl::Harl ( void ) {}

Harl::~Harl ( void ) {}

void    Harl::filter( std::string level ) {

    switch ( strToInt( level ) ) {

        case 0:
            debug();
            break;

        case 1:
            info();
            break;

        case 2:
            warning();
            break;

        case 3:
            error();
            break;

        case 4:
            insignificant();
            break;

    }

} 

void    Harl::debug( void ) {

    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl << std::endl;
    info();

}

void    Harl::info ( void ) {

    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!" << std::endl; 
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
    warning();

}

void    Harl::warning ( void ) {

    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
    error();
}

void    Harl::error ( void ) {

    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;

}

void    Harl::insignificant ( void ) {

    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

}

int     Harl::strToInt( std::string level ) {

    int value = 0;

    if ( level == "DEBUG" )
        value = Level( DEBUG );
    else if ( level == "INFO" ) 
        value = Level( INFO );
    else if ( level == "WARNING" )
        value = Level( WARNING );
    else if ( level == "ERROR" )
        value = Level( ERROR );
    else 
        value = Level( INSIGNIFICANT );
    
    return value;
}

bool    invalidArgs ( int argc ) {

    if ( argc != 2) {
        std::cout << "Invalid arguments: expected -> ./harlFilter \" level \"" << std::endl;
        return false;
    }

    return true;
}