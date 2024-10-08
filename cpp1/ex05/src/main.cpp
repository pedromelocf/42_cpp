#include "Harl.hpp"

int main ( void ) {

    Harl harl;

    harl.ptrToMemberFunc = &Harl::complain;

    (harl.*(harl.ptrToMemberFunc))("DEBUG");
    (harl.*(harl.ptrToMemberFunc))("INFO");
    (harl.*(harl.ptrToMemberFunc))("WARNING");
    (harl.*(harl.ptrToMemberFunc))("ERROR");
    (harl.*(harl.ptrToMemberFunc))("OTHER");
    
    return 0;
}