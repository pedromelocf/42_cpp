#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

	protected:
        std::string ideas[100];
		static const std::string invalidIndexMessage;

	public:
		Brain();
		Brain ( const Brain& b);
		Brain& operator= ( const Brain& b );
        ~Brain();

        void setBrain( int index, const std::string idea );
        const std::string& getBrain( int index ) const;

};

#endif
