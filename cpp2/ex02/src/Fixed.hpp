#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int _value;
		static const int _fracBits = 8;

	public:
		Fixed( void );
		Fixed  ( const Fixed& f);
		~Fixed( void );
		Fixed& operator= ( const Fixed& f);
		Fixed( const int i);
		Fixed ( const float f);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int	toInt ( void ) const;

		bool operator> ( const Fixed& f1) const;
		bool operator< ( const Fixed& f1) const;
		bool operator>= ( const Fixed& f1) const;
		bool operator<= ( const Fixed& f1) const;
		bool operator== ( const Fixed& f1) const;
		bool operator!= ( const Fixed& f1) const;

		Fixed operator+ (const Fixed& f1);
		Fixed operator- (const Fixed& f1);
		Fixed operator* (const Fixed& f1);
		Fixed operator/ (const Fixed& f1);

		static Fixed Fixed::min (Fixed& f1, Fixed& f2);
		static Fixed Fixed::min (const Fixed& f1, const Fixed& f2);
		static Fixed Fixed::max (Fixed& f1, Fixed& f2);
		static Fixed Fixed::max (const Fixed& f1, const Fixed& f2);

};

std::ostream& operator<< ( std::ostream& os, const Fixed& f);

#endif