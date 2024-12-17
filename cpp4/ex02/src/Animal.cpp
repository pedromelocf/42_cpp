#include "../includes/Animal.hpp"

// CONSTRUCTOR AND DESTRUCTOR

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "Animal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a) {
	*this = a;
	std::cout << "Animal Copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=( const AAnimal &a ) {

	if (this != &a)
		type = a.type;
	std::cout << "Animal Copy assignment operator called" << std::endl;
	return *this;

}

AAnimal::~AAnimal() {
	std::cout << "Animal Default destructor called" << std::endl;
}

// MEMBER FUNCTIONS

void AAnimal::makeSound() const {

	std::cout << "Class Animal does not make specific sounds" << std::endl;
}

const std::string AAnimal::getType() const {

	return type;
}
