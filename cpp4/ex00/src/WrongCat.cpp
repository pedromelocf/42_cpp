#include "../includes/WrongCat.hpp"

// CONSTRUCTOR AND DESTRUCTOR

WrongCat::WrongCat() {
	std::cout << "WrongCat Default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &c) {
	*this = c;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=( const WrongCat &c ) {

	if (this != &c)
		type = c.type;
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	return *this;

}

WrongCat::~WrongCat() {

	std::cout << "WrongCat Default destructor called" << std::endl;

}

// MEMBER FUNCTIONS

void WrongCat::makeSound() const
{
	std::cout << "Miau miau " << std::endl;
}
