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

Fixed::Fixed( const int i) : _value (i << this->_fracBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed ( const float f) : _value (roundf(f * (1 << this->_fracBits))) {
	std::cout << "Float constructor called" << std::endl;
}

int  Fixed::getRawBits( void ) const {
	return _value;
}

void	Fixed:: setRawBits( int const raw ) {
	_value = raw;
}

float	Fixed::toFloat ( void ) const {
	return ((float)this->_value / (1 << this->_fracBits)) ;
}

int	Fixed::toInt ( void ) const {
	return this->_value >> this->_fracBits;
}

std::ostream& operator<< ( std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return os;
}
