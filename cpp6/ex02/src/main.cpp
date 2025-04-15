#include "../includes/Base.hpp"

int main () {

    std::srand(time(0));
    std::cout << "------*  TEST 1   *------" << std::endl;
    Base * p1 = generate();;

    std::cout << "Derived from type: ";
    identify(p1);

    std::cout << "Derived from type: ";
    identify(*p1);

    delete p1;

    std::cout << std::endl << "------*  TEST 2  *------" << std::endl;
    Base * p2 = generate();;

    std::cout << "Derived from type: ";
    identify(p2);

    std::cout << "Derived from type: ";
    identify(*p2);

    delete p2;

    std::cout << std::endl <<  "------*  TEST 3  *------" << std::endl;
    Base * p3 = generate();;

    std::cout << "Derived from type: ";
    identify(p3);

    std::cout << "Derived from type: ";
    identify(*p3);

    delete p3;

    std::cout << std::endl << "------*  TEST 4  *------" << std::endl;
    Base * p4 = generate();;

    std::cout << "Derived from type: ";
    identify(p4);

    std::cout << "Derived from type: ";
    identify(*p4);

    delete p4;
}