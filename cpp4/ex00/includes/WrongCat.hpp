#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "./WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat();
	WrongCat ( const WrongCat& c);
	WrongCat& operator= ( const WrongCat& d );
	~WrongCat();

	void makeSound() const;

};

#endif
