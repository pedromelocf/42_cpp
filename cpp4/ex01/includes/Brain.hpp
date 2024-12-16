#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

	protected:
		std::string ideas[100];

	public:
		Brain();
		Brain ( const Brain& b);
		Brain& operator= ( const Brain& b );
		~Brain();

};

#endif
