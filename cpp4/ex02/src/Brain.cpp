#include "../includes/Brain.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Brain::Brain() {
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &b) {

	for (int i = 0; i < 100; i++)
		ideas[i] = b.ideas[i];
	std::cout << "Brain Copy constructor called" << std::endl;
}

Brain &Brain::operator=( const Brain &b ) {

	if (this != &b) {
		for (int i = 0; i < 100; i++)
			ideas[i] = b.ideas[i];
	}
	std::cout << "Brain Copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Default destructor called" << std::endl;
}

void Brain::setBrain( int index, const std::string idea ) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

const std::string& Brain::getBrain( int index ) const {
	if (index >= 0 && index < 100)
		return ideas[index];
	return invalidIndexMessage;
}

const std::string Brain::invalidIndexMessage = "Invalid index";