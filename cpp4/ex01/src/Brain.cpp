#include "../includes/Brain.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Brain::Brain() {
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &a) {
	*this = a;
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
