#ifndef CLAPTRAP_HPP
#define  CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		ClapTrap( const std::string clapTrapName );
		ClapTrap( const ClapTrap& c);
		ClapTrap& operator= ( const ClapTrap& c);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void setName( const std::string& clapTrapName);
		void setHitPoints( unsigned int amount );
		void setEnergyPoints( unsigned int amount );
		void setAttackDamage( unsigned int amount );

		const std::string& getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
};

#endif