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
		static const std::string levels[4];
        int     strToInt( std::string level );

};


#endif 