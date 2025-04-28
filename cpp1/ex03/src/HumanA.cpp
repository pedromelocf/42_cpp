#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : name( name ), type( weapon ) {}

HumanA::~HumanA( void ) {}

void	HumanA::attack( void ) {
	std::cout << this->name << " attacks with weapon " << this->type.getType() << std::endl; 
}
