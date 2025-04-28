#include "Zombie.hpp"

int main (void) {

	// ----------------TEST1 ------------------

	std::cout << std::endl << "Test 1 :" << std::endl << std::endl;

	Zombie* VectorHorde = zombieHorde( 3, "Vector" );

	for ( int i = 0; i < 3; ++i) {

		VectorHorde[i].announce();
	}

	delete[] VectorHorde ;


	// ----------------TEST2 ------------------
	
	std::cout << std::endl << "Test 2 :" << std::endl << std::endl;

	Zombie* Pores = zombieHorde( 10, "Pores" );

	for ( int i = 0; i < 10; i++) {

		Pores[i].announce();

	}

	delete[] Pores ;


	// ----------------TEST3 ------------------
	
	std::cout << std::endl << "Test 3 :" << std::endl << std::endl;

	Zombie* Big = zombieHorde( 15, "Big" );

	for ( int i = 0; i < 15; i++) {

		Big[i].announce();

	}

	delete[] Big ;

	return ( 0 );
}