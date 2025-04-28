#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB {

	public:

		HumanB( std::string name );
		~HumanB();
		void attack( void );
		void setWeapon ( Weapon& weapon );

	private:

		std::string name;
		Weapon *type;
		
};

#endif
