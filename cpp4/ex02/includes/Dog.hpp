#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public AAnimal {

	private:
		Brain* _brain;

	public:
		Dog();
		Dog ( const Dog& d );
		Dog& operator= ( const Dog& d );
		~Dog();

		void makeSound() const;
		void setBrain( int index, const std::string& idea );
		const std::string& getBrain( int index ) const;
};

#endif
