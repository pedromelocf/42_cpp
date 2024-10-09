#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>

class Replace {

    public:
        Replace( int argc, char **argv );
        ~Replace( void );
        bool validate( void );
        void copyContent( void );

    private:
        int _argc;
        char** _argv;
        bool invalidArgs ( void );
        bool fileExists( void ) ;

};


#endif