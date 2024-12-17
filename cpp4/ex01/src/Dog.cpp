#include "../includes/Dog.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Dog::Dog() {
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &d) {

	type = d.type;
	_brain = new Brain(*d._brain);
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=( const Dog &d ) {

	if (this != &d) {
		type = d.type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*d._brain);
	}

	std::cout << "Dog Copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog() {

	std::cout << "Dog Default destructor called" << std::endl;
	delete _brain;
}

// MEMBER FUNCTIONS

void Dog::makeSound() const {

	std::cout << "Au auuuuu " << std::endl;
}

void Dog::setBrain( int index, const std::string& idea ) {

	_brain->Brain::setBrain( index, idea );
}

const std::string& Dog::getBrain( int index ) const {

	return _brain->Brain::getBrain( index );
}