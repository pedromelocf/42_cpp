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
		Fixed& operator= ( const Fixed& f);
		~Fixed( void );
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

		Fixed operator+ (const Fixed& f1) const;
		Fixed operator- (const Fixed& f1) const;
		Fixed operator* (const Fixed& f1) const;
		Fixed operator/ (const Fixed& f1) const;

	 	Fixed& operator++ ( void );
		Fixed operator++ ( int);
		Fixed& operator-- ( void );
		Fixed operator-- ( int );

		static Fixed& min (Fixed& f1, Fixed& f2);
		const static Fixed& min (const Fixed& f1, const Fixed& f2);
		static Fixed& max (Fixed& f1, Fixed& f2);
		const static Fixed& max (const Fixed& f1, const Fixed& f2);

};

std::ostream& operator<< ( std::ostream& os, const Fixed& f);

#endif