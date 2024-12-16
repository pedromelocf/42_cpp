#include "../includes/WrongAnimal.hpp"

// CONSTRUCTOR AND DESTRUCTOR

WrongAnimal::WrongAnimal() : type("Wrong Animal") {
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a) {
	*this = a;
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &a ) {

	if (this != &a)
		type = a.type;
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	return *this;

}

WrongAnimal::~WrongAnimal() {

	std::cout << "WrongAnimal Default destructor called" << std::endl;

}

// MEMBER FUNCTIONS

void WrongAnimal::makeSound() const
{
	std::cout << "Class WrongAnimal does not make specific sounds" << std::endl;
}

const std::string WrongAnimal::getType() const
{
	return type;
}