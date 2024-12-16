#include "../includes/Dog.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Dog::Dog() {
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &d) {
	*this = d;
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=( const Dog &d ) {

	if (this != &d)
		type = d.type;
	std::cout << "Dog Copy assignment operator called" << std::endl;
	return *this;

}

Dog::~Dog() {
	std::cout << "Dog Default destructor called" << std::endl;
	delete brain;
}

// MEMBER FUNCTIONS

void Dog::makeSound() const {
	std::cout << "Au auuuuu " << std::endl;
}

void Dog::setBrain() const {

}

const std::string& Dog::getBrain() const {

}