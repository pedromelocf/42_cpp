#include "Harl.hpp"

int main ( int argc, char **argv ) {

	if ( !invalidArgs ( argc ) )
		return 1;

	Harl harl;

	harl.filter( argv[1] );

	return 0;
}