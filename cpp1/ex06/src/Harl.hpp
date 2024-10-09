#ifndef HARL_HPP
# define HARL_HPP

#include "iostream"



class Harl {

    public :    
        Harl ( void );
        ~Harl ( void );
        void    filter ( std::string level );

    private:
        void    debug( void );
        void    info ( void );
        void    warning ( void );
        void    error ( void );
        void    insignificant ( void );
        enum    Level{DEBUG, INFO, WARNING, ERROR}; 

};


#endif 