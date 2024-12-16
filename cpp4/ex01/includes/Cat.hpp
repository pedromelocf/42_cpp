#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal {

	private:
		Brain* brain;

	public:
		Cat();
		Cat ( const Cat& c);
		Cat& operator= ( const Cat& c );
		~Cat();

		void makeSound() const;
		void setBrain() const;
		const std::string& getBrain() const;

};

#endif
