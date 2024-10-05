#include "Zombie.hpp"

int main (void) {

    std::cout << "Test 1 :" << std::endl;

    Zombie* VectorHorde = zombieHorde( 3, "Vector" );

    for ( int i = 0; i < 3; i++) {
        VectorHorde[i].announce();
    }

    delete ( VectorHorde );


    std::cout << "Test 2 :" << std::endl;

    Zombie* Pores = zombieHorde( -1, "Pores" );

    for ( int i = 0; i < 3; i++) {
        Pores[i].announce();
    }

    delete ( Pores );


    std::cout << "Test 3 :" << std::endl;

    Zombie* Big = zombieHorde( 15, "Big" );

    for ( int i = 0; i < 3; i++) {
        Big[i].announce();
    }

    delete ( Big );

    return ( 0 );
}