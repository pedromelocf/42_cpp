#ifndef HARL_HPP
# define HARL_HPP

#include "iostream"

class Harl {

    public :    
        Harl ( void );
        ~Harl ( void );
        void    complain ( std::string level );
        void    ( Harl::*ptrToMemberFunc)( std::string );

    private:
        void    debug( void );
        void    info ( void );
        void    warning ( void );
        void    error ( void );
        void    invalid ( void );


};

#endif 