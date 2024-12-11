#include "ScavTrap.hpp"

// CONSTRUCTOR AND DESTRUCTOR

ScavTrap::ScavTrap(const std::string scavTrapName) : _name(scavTrapName), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap() : _name(""), _hitPoints(100), _energyPoints(50), _attackDamage (20) {
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &s) {
	*this = s;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &s) {
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	_name = s._name;
	_hitPoints= s._hitPoints;
	_energyPoints = s._hitPoints;
	_attackDamage = s._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Default destructor called" << std::endl;
}

// MEMBERS FUNCTIONS

void ScavTrap::attack(const std::string &target) {

	if ( _energyPoints > 0 )
	{
		_energyPoints -= 1;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
				  << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << "has not enough energy points. " << std::endl;

}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}