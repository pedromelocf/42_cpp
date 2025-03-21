#include "../includes/ClapTrap.hpp"

// CONSTRUCTOR AND DESTRUCTOR

ClapTrap::ClapTrap(const std::string& clapTrapName) : _name(clapTrapName),
	_hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << "ClapTrap Named Constructor called" << std::endl;
}

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10),
	_attackDamage (0) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c) {
	*this = c;
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c) {

	if (this != &c)
	{
		_name = c._name;
		_hitPoints= c._hitPoints;
		_energyPoints = c._hitPoints;
		_attackDamage = c._attackDamage;
	}
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	return *this;

}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Default destructor called" << std::endl;
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

// SETTERS

void ClapTrap::setName( const std::string& clapTrapName ) {
	_name = clapTrapName;
}

void ClapTrap::setHitPoints( unsigned int amount ) {
	_hitPoints = amount;
}

void ClapTrap::setEnergyPoints( unsigned int amount ) {
	_energyPoints = amount;
}

void ClapTrap::setAttackDamage( unsigned int amount ) {
	_attackDamage = amount;
}

// GETTERS

const std::string& ClapTrap::getName() const {
	return _name;
}

unsigned int ClapTrap::getHitPoints() const {
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}