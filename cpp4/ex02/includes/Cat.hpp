#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public AAnimal {

	private:
		Brain* _brain;

	public:
		Cat();
		Cat ( const Cat& c);
		Cat& operator= ( const Cat& c );
		~Cat();

		void makeSound() const;
		void setBrain( int index, const std::string idea );
		const std::string& getBrain( int index ) const;

};

#endif
