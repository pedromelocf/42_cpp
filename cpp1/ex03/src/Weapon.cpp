#include "Weapon.hpp"

Weapon::Weapon( std::string type) {
    this->type = type;
}

Weapon::~Weapon ( void ) {
    std::cout << "Destructor weapon called" << std::endl;
}

const std::string Weapon::getType( void ) {
    return ( this->type );
}

void Weapon::setType( std::string type ) {
    this->type = type;
}   
