#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

static void correctAnimalClassTest();
static void wrongAnimalClassTest();

int main()
{
	correctAnimalClassTest();
	wrongAnimalClassTest();
  	return 0;
}

static void correctAnimalClassTest(){

	std::cout << "----- Correct Animal Class tests -----" << std::endl;

	const Animal* a = new Animal();
	const Animal* b = new Dog();
	const Animal* c = new Cat();
	const Animal d = *b;
	const Animal e(*c);

	std::cout << std::endl <<  "a type: " << a->getType() << " " << std::endl;
	std::cout << "b type: " << b->getType() << " " << std::endl;
	std::cout << "c type: " << c->getType() << " " << std::endl;
	std::cout << "d type: " << d.getType() << " " << std::endl;
	std::cout << "e type: " << e.getType() << " " << std::endl << std::endl;

	a->makeSound();
//	b->Animal::makeSound();
	b->makeSound();
	c->makeSound();
	d.makeSound();
	e.makeSound();

	std::cout << std::endl;

	delete a;
	delete b;
	delete c;

	std::cout << "----- Correct Animal Class tests end -----" << std::endl;

}

static void wrongAnimalClassTest(){

	std::cout << std::endl <<  "----- Wrong Animal Class tests -----" << std::endl;

	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();
	const WrongAnimal c = *a;
	const WrongAnimal d(c);
	const WrongCat e;

	std::cout << std::endl << "a type: " << a->getType() << " " << std::endl;
	std::cout << "b type: " << b->getType() << " " << std::endl;
	std::cout << "c type: " << c.getType() << " " << std::endl;
	std::cout << "d type: " << d.getType() << " " << std::endl;
	std::cout << "e type: " << e.getType() << " " << std::endl << std::endl ;

	a->makeSound();
	b->makeSound();
	c.makeSound();
	d.makeSound();
	e.makeSound();

	std::cout << std::endl;

	delete a;
	delete b;

	std::cout << "----- Wrong Animal Class tests end-----" << std::endl;

}