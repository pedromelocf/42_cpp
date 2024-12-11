#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void testIndividualities();
static void testAttack ();
static void testDamage ();
static void testRepaired ();
static void testEnergyPoints ();

int main (void){

	testIndividualities();
    testAttack();
    testDamage();
    testRepaired();
    testEnergyPoints();

    return 0;
}

static void testIndividualities() {

	std::cout << "-----Individualities test-----" << std::endl;

	std::cout << "-----Individualities test end-----" << std::endl ;

}

static void testAttack () {

    std::cout << "-----Attack test-----" << std::endl;

    std::cout << "-----Attack test end-----" << std::endl ;
}

static void testDamage () {

    std::cout << std::endl << "-----Damage test-----" << std::endl;

    std::cout << "-----Damage test end-----" << std::endl;
}

static void testRepaired () {

    std::cout << std::endl << "-----Repaired test-----" << std::endl;

    std::cout << "-----Repaired test end-----" << std::endl ;
}

static void testEnergyPoints () {

    std::cout << std::endl << "-----Energy Points test-----" << std::endl;

    std::cout << "-----Energy Point test end-----" << std::endl;
}

