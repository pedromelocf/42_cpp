#include "Fixed.hpp"

FixedPointNumber::FixedPointNumber( void ) {

    std::cout << "Default constructor called" << std::endl;

}

FixedPointNumber::FixedPointNumber  ( const FixedPointNumber &f) {

    std::cout << "Copy constructor called" << std::endl;

}

FixedPointNumber::~FixedPointNumber( void ) {

    std::cout << "Destructor called" << std::endl;

}

FixedPointNumber::FixedPointNumber & operator= ( const FixedPointNumber &f) {

    std::cout << "Copy assignment operator calle" << std::endl;

}

int     FixedPointNumber::getRawBits( void ) const {

    std::cout << "getRawBits member function called" << std::endl;
    std::cout << value << std::endl;

    return value;
}

void    FixedPointNumber:: setRawBits( int const raw ) {

    value = raw;

}