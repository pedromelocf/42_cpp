#include "ClapTrap.hpp"

// CONSTRUCTOR AND DESTRUCTOR

ClapTrap::ClapTrap() : _name(), _hitPoints(10), _energyPoints(10), _attackDamage (0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string clapTrapName) : _name(clapTrapName), _hitPoints(10), _energyPoints(10), _attackDamage (0){
}

ClapTrap::ClapTrap(const ClapTrap &f) {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c) {
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Default destructor called" << std::endl;
}

// MEMBER FUNCTIONS

void ClapTrap::attack(const std::string &target) {

}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}
