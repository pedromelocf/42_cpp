#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>

class Replace {

    public:
        Replace( int argc, char **argv );
        ~Replace();
        bool validate();
        void copyContent();

    private:
        int _argc;
        char** _argv;
        bool invalidArgs();
        bool fileExists() ;

};


#endif