#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public Animal {

	private:
		Brain* brain;

	public:
		Dog();
		Dog ( const Dog& d );
		Dog& operator= ( const Dog& d );
		~Dog();

		void makeSound() const;
		void setBrain() const;
		const std::string& getBrain() const;

};

#endif
