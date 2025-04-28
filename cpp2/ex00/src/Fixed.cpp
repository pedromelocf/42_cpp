#include "Fixed.hpp"

Fixed::Fixed( void ) : _value (0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const Fixed& f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed ( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= ( const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	_value = f.getRawBits();
	return *this;
}

int	 Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed:: setRawBits( int const raw ) {
	_value = raw;
}