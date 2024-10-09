#include "Harl.hpp"

int main ( void ) {

    Harl harl;

    harl.ptrToMemberFunc = &Harl::complain; // setting pointer to member function "complain"

    std::cout << "<--------( TEST 1 )----------->" << std::endl;
    ( harl.*(harl.ptrToMemberFunc ))("DEBUG");
    std::cout << std::endl;

    std::cout << "<--------( TEST 2 )----------->" << std::endl;
    ( harl.*(harl.ptrToMemberFunc ))("INFO");
    std::cout << std::endl;
    
    std::cout << "<--------( TEST 3 )----------->" << std::endl;
    ( harl.*(harl.ptrToMemberFunc ))("WARNING");
    std::cout << std::endl;

    std::cout << "<--------( TEST 4 )----------->" << std::endl;
    ( harl.*(harl.ptrToMemberFunc ))("ERROR");
    std::cout << std::endl;

    std::cout << "<--------( TEST 5 )----------->" << std::endl;
    ( harl.*(harl.ptrToMemberFunc ))("INVALID");
    std::cout << std::endl;

    return 0;
}