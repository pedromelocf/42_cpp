#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

static void testConstructorDestructor( Animal **a );
static void testDog( Animal **a);
static void testCat( Animal **a);

int main() {

	Animal** a = new Animal*[4];

	testConstructorDestructor(a);
	testDog(a);
	testCat(a);

	delete[] a;

  	return 0;
}

static void testConstructorDestructor( Animal **a ) {

	std::cout << "-----*---- TESTING CONSTRUCTORS AND DESTRUCTORS -----*----" << std::endl;

	std::cout << " -*- Creating dog instances -*- " << std::endl;

	for (int i = 0; i < 2; i++){
		a[i] = new Dog();
		std::cout << std::endl;
	}

	std::cout << " -*- Creating cat instances -*- " << std::endl;

	for (int i = 2; i < 4; i++){
		a[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << " -*- Deleting all instances -*- " << std::endl;

	for (int i = 0; i < 4; i++) {
		delete a[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;

}

static void testDog( Animal **a) {

	std::cout << "-----*---- TESTING DOG  -----*----" << std::endl;

	a[0] = new Dog();
	a[0]->getType();
	a[0]->makeSound();

	std::cout << std::endl;

}

static void testCat( Animal **a) {

	std::cout << "-----*---- TESTING CAT  -----*----" << std::endl;

	a[0] = new Cat();
	a[0]->getType();
	a[0]->makeSound();

	std::cout << std::endl;

}