#include "Zombie.hpp"

int main (void) {

	randomChump( "Hector" );
	randomChump( "Elvis" );
	randomChump( "Jane" );


	Zombie* Walter = newZombie ( "Walter" );
	Walter->announce();
	delete Walter;


	Zombie* Pedro = newZombie ( "Pedro" );
	Pedro->announce();
	delete Pedro;


	Zombie* Kace = newZombie ( "Kace" );
	Kace->announce();
	delete Kace;


	return (0);
}