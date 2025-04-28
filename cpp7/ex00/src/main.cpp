#include "../includes/whatever.hpp"

int main( void ) {

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;

	std::string c = "test1";
	std::string d = "test2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;

	float f = 32.3f;
	float g = 32.1f;

	::swap(f, g);
	std::cout << "f = " << f << ", g = " << g << std::endl;
	std::cout << "min( f, g ) = " << ::min( f, g ) << std::endl;
	std::cout << "max( f, g ) = " << ::max( f, g ) << std::endl << std::endl;

	double h = 3998.0;
	double e = 3998.7;

	::swap(h, e);
	std::cout << "h = " << h << ", e = " << e << std::endl;
	std::cout << "min( h, e ) = " << ::min( h, e ) << std::endl;
	std::cout << "max( h, e ) = " << ::max( h, e ) << std::endl;

	return 0;
}