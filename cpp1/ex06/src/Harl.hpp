#ifndef HARL_HPP
# define HARL_HPP

#include "iostream"
#include "string"

bool    invalidArgs ( int argc );

class Harl {

    public :
        Harl ();
        ~Harl ();
        void    filter ( std::string level );

    private:
        void    debug();
        void    info ();
        void    warning ();
        void    error ();
        void    insignificant ();
        int     strToInt( std::string level );

};


#endif