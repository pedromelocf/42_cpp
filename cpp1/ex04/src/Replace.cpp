#include "Replace.hpp"

Replace::Replace( int argc, char** argv ) : _argc( argc ), _argv( argv ) {}

Replace::~Replace() {}

bool    Replace::validate () {

    if ( this->invalidArgs() && this->fileExists() )
        return true;
    return false;

}

void    Replace::copyContent () {

    std::string newFile( this->_argv[1] );
    newFile.append( ".replace" );
    std::ofstream outfile ( newFile.c_str(), std::ios::trunc );

    std::string line;
    std::ifstream inputFile( this->_argv[1] );

    std::string s1( this->_argv[2] );
    std::string s2( this->_argv[3] );

    while ( std::getline( inputFile, line )) {

        std::string newLine;

        for ( long unsigned int i = 0; i < line.length(); i += 1 ) {

            if (( line.length() >= s1.length() + i ) && ( !line.compare( i, s1.length(), s1 ))) {
                newLine += s2;
                i += s1.length() - 1;
            }

            else
                newLine += line[i];
        }

        outfile << newLine << std::endl;
    }

    inputFile.close();
    outfile.close();

}

bool    Replace::invalidArgs () {

    if ( this->_argc != 4) {
        std::cout << "Invalid arguments: expected -> \"FILENAME\" \"S1\" \"S2\"" << std::endl;
        return false;
    }

    return true;
}

bool    Replace::fileExists() {

    std::ofstream fio( this->_argv[1], std::ios::in );

    if ( !fio.is_open() ) {
        std::cout << "Invalid FILENAME: expected -> valid file" << std::endl;
        return false;
    }

    fio.close();
    return true;

}
