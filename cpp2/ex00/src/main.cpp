#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}

// The purpose of the copy constructor and the copy assignment 
// operator are almost equivalent -- both copy one object to another. 
// However, the copy constructor initializes new objects, whereas the 
// assignment operator replaces the contents of existing objects.

// -  If a new object has to be created before the copying can occur, 
// the copy constructor is used (note: this includes passing or returning
//  objects by value).
 
// If a new object does not have to be created before the copying
//  can occur, the assignment operator is used.

// https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/