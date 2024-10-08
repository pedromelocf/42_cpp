#include "Replace.hpp"

Replace::Replace( int argc, char** argv ) : _argc( argc ), _argv(argv) {}

Replace::~Replace( void ) {}

bool    Replace::validate ( void ) {

    if ( !this->invalidArgs() || !this->fileExists() )
        return false;
    return true;

}

void    Replace::copyContent ( void ) {

    std::string newfile = this->createFile();
    

}

bool    Replace::invalidArgs ( void ) {

    if ( this->_argc != 4) {
        std::cout << "Invalid arguments: expected -> \"FILENAME\" \"S1\" \"S2\"" << std::endl;
        return false;
    }

    return true;
}

bool    Replace::fileExists( void ) {

    std::ofstream fio( this->_argv[1], std::ios::in );

    if ( !fio.is_open() ) {
        std::cout << "Invalid FILENAME: expected -> valid file" << std::endl;
        return false;
    }

    fio.close();
    return true;

}

std::string Replace::createFile( void ) {

    std::string newfile( this->_argv[1] );
    newfile.append( ".replace" );
    std::ofstream outfile ( newfile.c_str() );
    return newfile;

}