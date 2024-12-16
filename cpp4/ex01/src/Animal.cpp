#include "../includes/Animal.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Animal::Animal() : type("Animal") {
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &a) {
	*this = a;
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=( const Animal &a ) {

	if (this != &a)
		type = a.type;
	std::cout << "Animal Copy assignment operator called" << std::endl;
	return *this;

}

Animal::~Animal() {
	std::cout << "Animal Default destructor called" << std::endl;
}

// MEMBER FUNCTIONS

void Animal::makeSound() const {
	std::cout << "Class Animal does not make specific sounds" << std::endl;
}

const std::string Animal::getType() const {
	return type;
}