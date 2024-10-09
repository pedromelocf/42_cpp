#include "Replace.hpp"

int main ( int argc, char **argv ) {

    Replace replace( argc, argv );

    if ( !replace.validate( ) )
        return 1;
    
    replace.copyContent();

    return 0;

}