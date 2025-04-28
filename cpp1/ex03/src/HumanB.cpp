#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string name ) : name( name ) , type( NULL ) {}

HumanB::~HumanB() {}

void HumanB::attack() {
	if (this->type)
		std::cout << this->name << " attacks with weapon " << this->type->getType() << std::endl;
	else
		std::cout << this->name << " does not have a weapon " << std::endl;
}

void HumanB::setWeapon ( Weapon& weapon ) {
	this->type = &weapon;
}