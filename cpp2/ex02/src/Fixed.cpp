#include "Fixed.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Fixed::Fixed( void ) : _value (0) {}

Fixed::Fixed ( const Fixed& f) {
	*this = f;
}

Fixed::~Fixed ( void ) {}

Fixed& Fixed::operator= ( const Fixed& f) {
	_value = f.getRawBits();
	return *this;
}

Fixed::Fixed( const int i) : _value (i << this->_fracBits) {}

Fixed::Fixed ( const float f) : _value (roundf(f * (1 << this->_fracBits))) {}

// GETTER AND SETTER

int  Fixed::getRawBits( void ) const {
	return _value;
}

void	Fixed:: setRawBits( int const raw ) {
	_value = raw;
}

// TO INT/TO FLOAT

float	Fixed::toFloat ( void ) const {
	return ((float)this->_value / (1 << this->_fracBits));
}

int	Fixed::toInt ( void ) const {
	return this->_value >> this->_fracBits;
}

// OVERLOAD COMPARE

bool Fixed::operator> ( const Fixed& f1) const {
	if (this->toFloat() > f1.toFloat())
		return true;
	else
		return false;
};

bool Fixed::operator< ( const Fixed& f1) const {
	if (this->toFloat() < f1.toFloat())
		return true;
	else
		return false;
};

bool Fixed::operator>= ( const Fixed& f1) const {
	if (this->toFloat() >= f1.toFloat())
		return true;
	else
		return false;
};

bool Fixed::operator<= ( const Fixed& f1) const {
	if (this->toFloat() <= f1.toFloat())
		return true;
	else
		return false;
};

bool Fixed::operator== ( const Fixed& f1) const {
	if (this->toFloat() == f1.toFloat())
		return true;
	else
		return false;
};

bool Fixed::operator!= ( const Fixed& f1) const {
	if (this->toFloat() != f1.toFloat())
		return true;
	else
		return false;
};

// OVERLOAD ARITHMETIC OPERATIONS

Fixed Fixed::operator+ (const Fixed& f1) const {
	return Fixed(this->toFloat() + f1.toFloat());
};

Fixed Fixed::operator- (const Fixed& f1) const {
	return Fixed(this->toFloat() - f1.toFloat());
};

Fixed Fixed::operator* (const Fixed& f1) const {
	return Fixed(this->toFloat() * f1.toFloat());
};

Fixed Fixed::operator/ (const Fixed& f1) const {
	return Fixed(this->toFloat() / f1.toFloat());
};

// OVERLOAD INCREMENT/DECREMENT OPERATIONS

Fixed& Fixed::operator++ ( void ) {
	this->_value++;
	return *this;
};

Fixed Fixed::operator++ ( int ) {
	Fixed tmp (*this);
	this->_value++;
	return tmp;
};

Fixed& Fixed::operator-- ( void ) {
	this->_value--;
	return *this;
};

Fixed Fixed::operator-- ( int ) {
	Fixed tmp (*this);
	this->_value--;
	return tmp;
};


// OVERLOAD MAX/MIN

Fixed& Fixed::min (Fixed& f1, Fixed& f2) {
	if (f1.toFloat() < f2.toFloat())
		return f1;
	else
		return f2;
}

const Fixed& Fixed::min (const Fixed& f1, const Fixed& f2) {
	if (f1.toFloat() < f2.toFloat())
		return f1;
	else
		return f2;
}

Fixed& Fixed::max (Fixed& f1, Fixed& f2) {
	if (f1.toFloat() > f2.toFloat())
		return f1;
	else
		return f2;
}

const Fixed& Fixed::max (const Fixed& f1, const Fixed& f2) {
	if (f1.toFloat() > f2.toFloat())
		return f1;
	else
		return f2;
}

// OVERLOAD << TO STDOUT

std::ostream& operator<< ( std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return os;
}
