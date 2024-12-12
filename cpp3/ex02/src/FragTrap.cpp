#include "FragTrap.hpp"

// CONSTRUCTOR AND DESTRUCTOR

FragTrap::FragTrap() {

	setName("");
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap Default Constructor called" << std::endl;

}

FragTrap::FragTrap(const std::string& fragTrapName) {

	setName(fragTrapName);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap Named Constructor called" << std::endl;

}

FragTrap::FragTrap(const FragTrap &f) {

	*this = f;
	std::cout << "FragTrap Copy constructor called" << std::endl;

}

FragTrap &FragTrap::operator=(const FragTrap &f) {

	if (this != &f) {
		setName(f.getName());
		setHitPoints(f.getHitPoints());
		setEnergyPoints(f.getEnergyPoints());
		setAttackDamage(f.getAttackDamage());
	}
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return *this;

}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor Called" << std::endl;
}

// MEMBERS FUNCTIONS

void FragTrap::highFiveGuys() {
	if (getEnergyPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << getName() << " says: High five guys ! " << std::endl;
	}
	else
		std::cout << getName() << " does not have enought energy points to High Five." << std::endl;
}
