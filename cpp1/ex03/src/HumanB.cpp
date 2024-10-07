#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string name ) : name( name ) , type( NULL ) {}

HumanB::~HumanB( void ) {}

void HumanB::attack( void ) {
    std::cout << this->name << " attacks with weapon " << this->type->getType() << std::endl; 
}

void HumanB::setWeapon ( Weapon& weapon ) {
    this->type = &weapon;
}