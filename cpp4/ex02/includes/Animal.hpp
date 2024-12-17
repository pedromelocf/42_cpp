#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {

	protected:
		std::string type;

  	public:
		 AAnimal();
		 AAnimal( const AAnimal& a);
		 AAnimal& operator= ( const AAnimal& a );
		 virtual ~AAnimal();

		 virtual void makeSound() const = 0;
		 const std::string getType() const;

};

#endif
