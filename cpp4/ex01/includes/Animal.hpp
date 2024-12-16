#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

	protected:
		std::string type;

  	public:
		 Animal();
		 Animal( const Animal& a);
		 Animal& operator= ( const Animal& a );
		 virtual ~Animal();

		 virtual void makeSound() const;
		 const std::string getType() const;

};

#endif
