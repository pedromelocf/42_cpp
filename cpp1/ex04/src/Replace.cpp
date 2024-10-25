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
	if (!outfile.is_open()) {
		std::cerr << "Failed to open file " << newFile << std::endl;
		return ;
	}

    std::ifstream inputFile( this->_argv[1] );
	if (!inputFile.is_open()) {
		std::cerr << "Failed to open file " << this->_argv[1] << std::endl;
		return ;
	}

	std::string s1( this->_argv[2] );
    std::string s2( this->_argv[3] );
	std::string line;

    while ( std::getline( inputFile, line )) {

		size_t	pos = 0, occ = 0;

		while ((pos = line.find(s1, occ)) != std::string::npos) {

			outfile << line.substr(occ, pos - occ) << s2;
			occ = pos + s1.length();

		}
		outfile << line.substr(occ) << std::endl;
    }

    inputFile.close();
    outfile.close();

}

bool    Replace::invalidArgs () {

    if ( this->_argc != 4 ) {
        std::cout << "Invalid arguments: expected -> \"FILENAME\" \"S1\" \"S2\"" << std::endl;
        return false;
    }

	std::string s1( this->_argv[2] );
	if (s1.empty()){
		std::cout << "Invalid s1 : expected -> not empty" << std::endl;
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
