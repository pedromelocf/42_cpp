#include "Harl.hpp"

int main () {

	Harl	harl;

	std::cout << "<--------( TEST 1 )----------->" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "<--------( TEST 2 )----------->" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "<--------( TEST 3 )----------->" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "<--------( TEST 4 )----------->" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "<--------( TEST 5 )----------->" << std::endl;
	harl.complain("INVALID");
	std::cout << std::endl;

	return 0;
}