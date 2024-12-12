#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

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

	ScavTrap scav1("Scav1");
	std::cout << std::endl;

	ScavTrap scav2(scav1);
	std::cout << std::endl;

	ScavTrap scav3;
	std::cout << std::endl;

	scav3 = scav1;
	std::cout << std::endl;

	std::cout << "Test ScavTrap names" << std::endl;
	std::cout << scav1.getName() << std::endl;
	std::cout << scav2.getName() << std::endl;
	std::cout << scav3.getName() << std::endl << std::endl;

	std::cout << "Test ScavTrap hit points" << std::endl;
	std::cout << scav1.getHitPoints() << std::endl;
	std::cout << scav2.getHitPoints() << std::endl;
	std::cout << scav3.getHitPoints() << std::endl << std::endl;

	std::cout << "Test ScavTrap energy points" << std::endl;
	std::cout << scav1.getEnergyPoints() << std::endl;
	std::cout << scav2.getEnergyPoints() << std::endl;
	std::cout << scav3.getEnergyPoints() << std::endl << std::endl;

	std::cout << "Test ScavTrap attack damage" << std::endl;
	std::cout << scav1.getAttackDamage() << std::endl;
	std::cout << scav2.getAttackDamage() << std::endl;
	std::cout << scav3.getAttackDamage() << std::endl << std::endl;

	std::cout << "-----Constructor destructor test end-----" << std::endl ;

}

static void testIndividualities() {

	std::cout << std::endl << "-----Individualities test-----" << std::endl;

	ScavTrap scav("Lenny");
	scav.guardGate();
	scav.attack("Michael");
	std::cout << std::endl;

	ClapTrap clap("Jason");
//	clap.guardGate();
	clap.attack("Michael");
	std::cout << std::endl;

	std::cout << "-----Individualities test end-----" << std::endl ;

}

static void testDamage () {

    std::cout << std::endl << std::endl << "-----Damage test-----" << std::endl;

	ScavTrap scav("Penguin");
	scav.takeDamage(10);
	std::cout << std::endl;

	ClapTrap clap("Peacekeeper");
	clap.takeDamage(5);
	std::cout << std::endl;

    std::cout << "-----Damage test end-----" << std::endl;
}

static void testRepaired () {

    std::cout << std::endl << std::endl << "-----Repaired test-----" << std::endl;

	ScavTrap scav("Janis");
	scav.beRepaired(10);
	std::cout << std::endl;

	ClapTrap clap("Peacekeeper");
	clap.beRepaired(5);
	std::cout << std::endl;

    std::cout << "-----Repaired test end-----" << std::endl ;
}

static void testEnergyPoints () {

    std::cout << std::endl << std::endl << "-----Energy Points test-----" << std::endl;

	ScavTrap scav("Homelander");
	std::cout << scav.getName() << " has " << scav.getEnergyPoints() << " energy points left." << std::endl << std::endl;

	ClapTrap clap("Peacekeeper");
	std::cout  << clap.getName() << " has " << clap.getEnergyPoints() << " energy points left." << std::endl << std::endl;

    std::cout << "-----Energy Point test end-----" << std::endl;
}
