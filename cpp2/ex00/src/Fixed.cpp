#include "Fixed.hpp"

Fixed::Fixed( void ) : value (0) {

    std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed  ( const Fixed& f) : value( f.value ) {

    std::cout << "Copy constructor called" << std::endl;

}

Fixed::~Fixed( void ) {

    std::cout << "Destructor called" << std::endl;

}

Fixed& Fixed::operator= ( const Fixed& f) {

    std::cout << "Copy assignment operator called" << std::endl;

    value = f.value;

    return *this;

}

int     Fixed::getRawBits( void ) const {

    std::cout << "getRawBits member function called" << std::endl;

    return value;
}

void    Fixed:: setRawBits( int const raw ) {

    value = raw;

}