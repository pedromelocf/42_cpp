#include "Harl.hpp"

Harl::Harl () {}

Harl::~Harl () {}

const	std::string Harl::levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

void    Harl::filter( std::string level ) {

    switch ( strToInt( level ) ) {

        case 0:
            debug();

        case 1:
            info();

        case 2:
            warning();

        case 3:
            error();
			break;

        case 4:
            insignificant();
			break;
    }

} 

void    Harl::debug() {

    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl << std::endl;

}

void    Harl::info () {

    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!" << std::endl; 
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;

}

void    Harl::warning () {

    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void    Harl::error () {

    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;

}

void    Harl::insignificant () {

    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

}

int     Harl::strToInt( std::string level ) {

	for ( int i = 0; i < 4; i++ ) {
		if ( level == levels[i] )
			return i;
	}
	return 4;

}

bool    invalidArgs ( int argc ) {

    if ( argc != 2) {
        std::cout << "Invalid arguments: expected -> ./harlFilter \" level \"" << std::endl;
        return false;
    }

    return true;
}