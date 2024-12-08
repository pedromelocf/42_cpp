#include "Fixed.hpp"

static void testArithmeticOper(void);
static void testComparisonOper(void);
static void testIncreDecreOper(void);
static void testMinMax(void);

int main( void ) {

	testArithmeticOper();
	testComparisonOper();
	testMinMax();

	return 0;
}

static void testArithmeticOper(void) {

	Fixed a;
	Fixed const b( Fixed( 5.1f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 35.10f ) / Fixed( 5 ) );
	Fixed const d( Fixed( 198.4f ) + Fixed( 12 ) );
	Fixed const e( Fixed( -32 ) - Fixed( 2 ) );

	std::cout << "-----Arithmetic tests -----" << std::endl;

	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	std::cout << "-----Arithmetic tests end -----" << std::endl;

}

static void testComparisonOper(void) {

	Fixed const b( 84 );
	Fixed const c( -34.8f );
	Fixed const d( 554.12f );
	Fixed const e( 554 );
	Fixed const f( -68);
	Fixed const g( -68.1f);

	std::cout << "-----Comparison tests-----" << std::endl;

	if (b > c)
		std::cout << "b > c" << std::endl;
	else
		std::cout << "b <= c" << std::endl;

	if (d < c)
		std::cout << "d < c" << std::endl;
	else
		std::cout << "d >= c" << std::endl;

	if (d >= e)
		std::cout << "d >= e" << std::endl;
	else
		std::cout << "d < e" << std::endl;

	if (b <= d)
		std::cout << "b <= d" << std::endl;
	else
		std::cout << "d > e" << std::endl;

	if (f == g)
		std::cout << "f == g" << std::endl;
	else
		std::cout << "f != g" << std::endl;

	if (e != g)
		std::cout << "e != g" << std::endl;
	else
		std::cout << "e == g" << std::endl;

	std::cout << "-----Comparison tests end-----" << std::endl;
}

// static void testIncreDecreOper(void) {

// 	Fixed a;

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// }

static void testMinMax (void) {

	Fixed a(30);
	Fixed b (30.1f);

	std::cout << Fixed::max( a, b) << std::endl;
}