#include "ClapTrap.hpp"

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

    sett.attack("Tim");
    empty.attack("Sett");

    std::cout << "-----Attack test end-----" << std::endl ;    
}

static void testDamage () {

    std::cout << std::endl << "-----Damage test-----" << std::endl;    

    ClapTrap dalle("Dalle");

    dalle.takeDamage(5);
    dalle.takeDamage(5);

    std::cout << "-----Damage test end-----" << std::endl;    
}

static void testRepaired () {

    std::cout << std::endl << "-----Repaired test-----" << std::endl;    
    
    ClapTrap brooks("Brooks");
    ClapTrap assig;

    assig = brooks;

    brooks.beRepaired(3);
    brooks.beRepaired(1000);
    assig.beRepaired(1);

    std::cout << "-----Repaired test end-----" << std::endl ;    
}

static void testEnergyPoints () {
    
    std::cout << std::endl << "-----Energy Points test-----" << std::endl;  

    ClapTrap tired("Tired");

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

    std::cout << "-----Energy Point test end-----" << std::endl;    
}


