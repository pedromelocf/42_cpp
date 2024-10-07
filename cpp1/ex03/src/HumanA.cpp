#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA( std::string name, Weapon type ) {
    
    this->name = name;
    this->type = type;

}

HumanA::~HumanA( void ) {
    std::cout << "Destructor HumanB called" << std::endl;
}

void    HumanA::attack( void ) {
    std::cout << this->name << "attacks with weapon" << this->type->type << std::endl; 
}
