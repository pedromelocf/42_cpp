#include "../includes/ClapTrap.hpp"

static void testAttack ();
static void testDamage ();
static void testRepaired ();
static void testEnergyPoints ();


int main (void){

	testAttack();
	testDamage();
	testRepaired();
	testEnergyPoints();

	return 0;
}

static void testAttack () {
	
	std::cout << "-----Attack test-----" << std::endl;   

	ClapTrap sett("Sett");
	ClapTrap empty;

	std::cout << std::endl;

	sett.attack("Tim");
	empty.attack("Sett");

	std::cout << std::endl << "-----Attack test end-----" << std::endl ;
}

static void testDamage () {

	std::cout << std::endl << "-----Damage test-----" << std::endl;	

	ClapTrap dalle("Dalle");

	std::cout << std::endl;

	dalle.takeDamage(5);
	dalle.takeDamage(5);

	std::cout << std::endl <<  "-----Damage test end-----" << std::endl;
}

static void testRepaired () {

	std::cout << std::endl << "-----Repaired test-----" << std::endl;	
	
	ClapTrap brooks("Brooks");

	std::cout << std::endl;

	brooks.beRepaired(3);
	brooks.beRepaired(1000);

	std::cout << std::endl << "-----Repaired test end-----" << std::endl ;
}

static void testEnergyPoints () {
	
	std::cout << std::endl << "-----Energy Points test-----" << std::endl;  

	ClapTrap tired("Tired");

	std::cout << std::endl;

	tired.attack("Tim");
	tired.attack("Brooks");
	tired.attack("Kevin");
	tired.attack("Denis");
	tired.attack("Luther");
	tired.beRepaired(2);
	tired.beRepaired(3);
	tired.beRepaired(1);
	tired.beRepaired(1);
	tired.beRepaired(4);
	tired.beRepaired(2);

	std::cout << std::endl << "-----Energy Point test end-----" << std::endl;
}


