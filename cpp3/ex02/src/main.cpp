#include "ClapTrap.hpp"
#include "FragTrap.hpp"

static void testConstructorDestructor();
static void testIndividualities();
static void testDamage ();
static void testRepaired ();
static void testEnergyPoints ();

int main (void){

	testConstructorDestructor();
	testIndividualities();
	testDamage();
	testRepaired();
	testEnergyPoints();

	return 0;
}

static void testConstructorDestructor() {

	std::cout << "-----Constructor destructor test-----" << std::endl;

	FragTrap frag1("Frag1");
	std::cout << std::endl;

	FragTrap frag2(frag1);
	std::cout << std::endl;

	FragTrap frag3;
	std::cout << std::endl;

	frag3 = frag1;
	std::cout << std::endl;

	std::cout << "Test FragTrap names" << std::endl;
	std::cout << frag1.getName() << std::endl;
	std::cout << frag2.getName() << std::endl;
	std::cout << frag3.getName() << std::endl << std::endl;

	std::cout << "Test FragTrap hit points" << std::endl;
	std::cout << frag1.getHitPoints() << std::endl;
	std::cout << frag2.getHitPoints() << std::endl;
	std::cout << frag3.getHitPoints() << std::endl << std::endl;

	std::cout << "Test FragTrap energy points" << std::endl;
	std::cout << frag1.getEnergyPoints() << std::endl;
	std::cout << frag2.getEnergyPoints() << std::endl;
	std::cout << frag3.getEnergyPoints() << std::endl << std::endl;

	std::cout << "Test FragTrap attack damage" << std::endl;
	std::cout << frag1.getAttackDamage() << std::endl;
	std::cout << frag2.getAttackDamage() << std::endl;
	std::cout << frag3.getAttackDamage() << std::endl << std::endl;

	std::cout << "-----Constructor destructor test end-----" << std::endl ;

}

static void testIndividualities() {

	std::cout << std::endl << "-----Individualities test-----" << std::endl;

	FragTrap frag("Lenny");
	frag.attack("Michael");
	std::cout << std::endl;

	ClapTrap clap("Jason");
	clap.attack("Michael");
	std::cout << std::endl;

	std::cout << "-----Individualities test end-----" << std::endl ;

}

static void testDamage () {

	std::cout << std::endl << std::endl << "-----Damage test-----" << std::endl;

	FragTrap frag("Penguin");
	frag.takeDamage(10);
	std::cout << std::endl;

	ClapTrap clap("Peacekeeper");
	clap.takeDamage(5);
	std::cout << std::endl;

	std::cout << "-----Damage test end-----" << std::endl;
}

static void testRepaired () {

	std::cout << std::endl << std::endl << "-----Repaired test-----" << std::endl;

	FragTrap frag("Janis");
	frag.beRepaired(10);
	std::cout << std::endl;

	ClapTrap clap("Peacekeeper");
	clap.beRepaired(5);
	std::cout << std::endl;

	std::cout << "-----Repaired test end-----" << std::endl ;
}

static void testEnergyPoints () {

	std::cout << std::endl << std::endl << "-----Energy Points test-----" << std::endl;

	FragTrap frag("Homelander");
	std::cout << frag.getName() << " has " << frag.getEnergyPoints() << " energy points left." << std::endl << std::endl;

	ClapTrap clap("Peacekeeper");
	std::cout  << clap.getName() << " has " << clap.getEnergyPoints() << " energy points left." << std::endl << std::endl;

	std::cout << "-----Energy Point test end-----" << std::endl;
}
