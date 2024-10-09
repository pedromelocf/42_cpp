#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class FixedPointNumber {

    private:
        int value;
        static const int fracBits = 8;

    public:
        FixedPointNumber( void );
        FixedPointNumber  ( const FixedPointNumber &f);
        ~FixedPointNumber( void );
        FixedPointNumber & operator= ( const FixedPointNumber &f);
        int getRawBits( void ) const;
        void setRawBits( int const raw );

};

#endif