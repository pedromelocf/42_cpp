#include "Harl.hpp"

Harl::Harl ( void ) {}

Harl::~Harl ( void ) {}

void    Harl::filter( std::string level ) {

    switch ( Level( level ) ) {

        case DEBUG:
            debug();
            break;

        case INFO:
            info();
            break;

        case WARNING:
            warning();
            break;

        case ERROR:
            error();
            break;

        default:
            insignificant();
            break;

    }

} 

void    Harl::debug( void ) {

    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
    info();
    warning();
    error();

}

void    Harl::info ( void ) {

    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!" << std::endl; 
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
    warning();
    error();

}

void    Harl::warning ( void ) {

    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
    error();
}

void    Harl::error ( void ) {

    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;

}

void    Harl::insignificant ( void ) {

    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

}
