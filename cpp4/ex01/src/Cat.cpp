#include "../includes/Cat.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Cat::Cat() {
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &c) {

	type = c.type;
	_brain = new Brain(*c._brain);
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=( const Cat &c ) {

	if (this != &c) {
		type = c.type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*c._brain);
	}

	std::cout << "Cat Copy assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat() {

	std::cout << "Cat Default destructor called" << std::endl;
	delete _brain;
}

// MEMBER FUNCTIONS

void Cat::makeSound() const
{
	std::cout << "Miau miau " << std::endl;
}

void Cat::setBrain( int index, const std::string idea ) {

	_brain->Brain::setBrain( index ,idea );
}

const std::string& Cat::getBrain( int index ) const {

	return _brain->Brain::getBrain( index );
}