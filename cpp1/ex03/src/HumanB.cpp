#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string name ) {
    this->name = name;
}

HumanB::~HumanB( void ) {
    std::cout << "Destructor humanb called" << std::endl;
}

void HumanB::attack( void ) {
    std::cout << this->name << "attacks with weapon" << this->type->getType() << std::endl; 
}

void HumanB::setWeapon ( Weapon weapon ) {
    this->type.setType( weapon );
}