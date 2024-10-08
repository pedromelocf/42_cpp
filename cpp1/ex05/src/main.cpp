#include "Harl.hpp"

int main ( void ) {

    Harl harl();

    // harl.complain("DEBUG");

    void (Harl::*ptrToMemberFunc)(std::string) = &Harl::complain;

    void (harl.*ptrToMemberFunc)("DEBUG");

    return 0;
}