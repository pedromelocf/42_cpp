#include "ScavTrap.hpp"

// CONSTRUCTOR AND DESTRUCTOR

ScavTrap::ScavTrap() {

	setName("");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap Default constructor called" << std::endl;

}

ScavTrap::ScavTrap(const std::string scavTrapName) {

	setName(scavTrapName);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap Named Constructor called" << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap &s) {

	*this = s;
	std::cout << "ScavTrap Copy constructor called" << std::endl;

}

ScavTrap &ScavTrap::operator=(const ScavTrap &s) {

	setName(s.getName());
	setHitPoints(s.getHitPoints());
	setEnergyPoints(s.getEnergyPoints());
	setAttackDamage(s.getAttackDamage());
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return *this;

}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Default destructor called" << std::endl;
}

// MEMBERS FUNCTIONS

void ScavTrap::attack(const std::string &target) {

	if ( getEnergyPoints() > 0 )
	{
		setEnergyPoints( getEnergyPoints() -1 );
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
				  << getAttackDamage() << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << getName() << "has not enough energy points. " << std::endl;

}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
