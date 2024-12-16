#include "../includes/Cat.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Cat::Cat() {
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &c) {
	*this = c;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=( const Cat &c ) {

	if (this != &c)
		type = c.type;
	std::cout << "Cat Copy assignment operator called" << std::endl;
	return *this;

}

Cat::~Cat() {

	std::cout << "Cat Default destructor called" << std::endl;

}

// MEMBER FUNCTIONS

void Cat::makeSound() const
{
	std::cout << "Miau miau " << std::endl;
}
