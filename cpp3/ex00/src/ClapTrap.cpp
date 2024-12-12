#include "ClapTrap.hpp"

// CONSTRUCTOR AND DESTRUCTOR

ClapTrap::ClapTrap(const std::string& clapTrapName) : _name(clapTrapName),
	_hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10),
	_attackDamage (0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c) {
	*this = c;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c) {
	std::cout << "Copy assignment operator called" << std::endl;
	_name = c._name;
	_hitPoints= c._hitPoints;
	_energyPoints = c._hitPoints;
	_attackDamage = c._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Default destructor called" << std::endl;
}

// MEMBER FUNCTIONS

void ClapTrap::attack(const std::string &target) {

	if ( _energyPoints > 0 )
	{
		_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
		<< _attackDamage << " points of damage!" << std::endl;
	}
	else 
		std::cout << "ClapTrap " << _name << "has not enough energy points. " << std::endl;	
}

void ClapTrap::takeDamage(unsigned int amount) {

	_hitPoints -= amount;
	std::cout << "ClaptTrap " << _name << " got hit, causing " << amount
	<< " points of damage, and now got " << _hitPoints << " left." << std::endl;

	if ( _hitPoints <= 0 )
	{
		std::cout << "ClapTrap " << _name << " died!" << std::endl;
	}

}

void ClapTrap::beRepaired(unsigned int amount) {

	if ( _energyPoints > 0 )
	{
		_energyPoints -= 1;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repaired itself, getting " << amount
		<< " points back, and now got " << _hitPoints << " left." << std::endl;
	}
	else 
		std::cout << "ClapTrap " << _name << " has not enough energy points." << std::endl;	
}
