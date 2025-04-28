#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

static void testConstructorDestructor();
static void testDog();
static void testCat();
static void testCatDeepCopies();
static void testDogDeepCopies();


int main() {

	testConstructorDestructor();
	testDog();
	testCat();
	testCatDeepCopies();
	testDogDeepCopies();

  	return 0;
}

static void testConstructorDestructor( ) {

	std::cout << "-----*---- TESTING CONSTRUCTORS AND DESTRUCTORS -----*----" << std::endl;

	Animal** a = new Animal*[4];

	std::cout << " -*- CREATING DOG INSTANCES -*- " << std::endl;

	for (int i = 0; i < 2; i++){
		a[i] = new Dog();
		std::cout << std::endl;
	}

	std::cout << " -*- CREATING CAT INSTANCES -*- " << std::endl;

	for (int i = 2; i < 4; i++){
		a[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << " -*- DELETING ALL INSTANCES -*- " << std::endl;

	for (int i = 0; i < 4; i++) {
		delete a[i];
		std::cout << std::endl;
	}

	delete[] a;

}

static void testDog( ) {

	std::cout << "-----*---- TESTING DOG -----*----" << std::endl;

	std::cout << "-*- INITIALIZING DOG JOE OBJECT -*-" << std::endl;

	Dog *joe = new Dog();

	std::cout << "Joe Type: " << joe->getType() << std::endl;
	joe->makeSound();
	joe->setBrain(0, "I love eating chicken bone!");
	joe->setBrain(1, "All I need is food");
	joe->setBrain(2, "I hate cats D: ");

	std::cout << "Joe's Brain (Index 0): " << joe->getBrain(0) << std::endl;
	std::cout << "Joe's Brain (Index 1): " << joe->getBrain(1) << std::endl;
	std::cout << "Joe's Brain (Index 2): " << joe->getBrain(2) << std::endl;
	std::cout << "Joe's Brain (Index 3): " << joe->getBrain(3) << " (Must be empty)" << std::endl;

	joe->setBrain(0, "I am very fluffy");
	std::cout << "Updated Joe's Brain (Index 0): " << joe->getBrain(0) << std::endl;

	std::cout << std::endl;
	std::cout << "-*- DELETING DOG JOE OBJECT -*-" << std::endl;

	delete joe;
}

static void testCat() {

	std::cout << std::endl << "-----*---- TESTING CAT  -----*----" << std::endl;

	std::cout << "-*- INITIALIZING CAT PRINCESS OBJECT -*-" << std::endl;

	Cat *princess = new Cat();

	std::cout << "Princess Type: " << princess->getType() << std::endl;
	princess->makeSound();
	princess->setBrain(4, "I require snacks immediately, or I shall perish dramatically.");
	princess->setBrain(5, "I slept 16 hours today. Tomorrow? A new record.");
	princess->setBrain(6, "Your keyboard is my throne, and I will not be moved.");

	std::cout << "Princess's Brain (Index 4): " << princess->getBrain(4) << std::endl;
	std::cout << "Princess's Brain (Index 5): " << princess->getBrain(5) << std::endl;
	std::cout << "Princess's Brain (Index 6): " << princess->getBrain(6) << std::endl;
	std::cout << "Princess's Brain (Index 7): " << princess->getBrain(7) << " (Must be empty)" << std::endl;

	princess->setBrain(4, "I am very fluffy");
	std::cout << "Updated Princess's Brain (Index 4): " << princess->getBrain(4) << std::endl;

	std::cout << std::endl;
	std::cout << "-*- DELETING CAT PRINCESS OBJECT -*-" << std::endl;

	delete princess;
}

static void testCatDeepCopies() {

	std::cout << std::endl << "-----*---- TESTING DEEP COPIES -----*----" << std::endl;

	std::cout << "-*- INITIALIZING CAT P OBJECT -*-" << std::endl;

	Cat *p = new Cat();

	p->setBrain(0, "Testing copies");
	p->setBrain(1, "I want to sleep");

	Cat temp1 = *p;
	Cat temp2(*p);

	std::cout << std::endl << "-*- DELETING CAT P OBJECT -*-" << std::endl;

	delete p;

	std::cout << std::endl;
	std::cout << "Temp1 index0: " << temp1.getBrain(0) << std::endl;
	std::cout << "Temp1 index1: " << temp1.getBrain(1) << std::endl;
	std::cout << "Temp1 type: " << temp1.getType() << std::endl;

	std::cout << std::endl;
	std::cout << "Temp2 index0: " << temp2.getBrain(0) << std::endl;
	std::cout << "Temp2 index1: " << temp2.getBrain(1) << std::endl;
	std::cout << "Temp2 type: " << temp2.getType() << std::endl;


	std::cout << std::endl;
	temp1.setBrain(0, "New idea");
	temp1.setBrain(1, "Sleep");

	std::cout << "New temp3" << std::endl;
	Cat temp3 = temp1;

	std::cout << std::endl;
	std::cout << "Temp3 index0: " << temp3.getBrain(0) << std::endl;
	std::cout << "Temp3 index1: " << temp3.getBrain(1) << std::endl;
	std::cout << "Temp3 type: " << temp3.getType() << std::endl;
	std::cout << std::endl;
}

static void testDogDeepCopies() {

	std::cout << std::endl << "-----*---- TESTING DOG DEEP COPIES -----*----" << std::endl;

	std::cout << "-*- INITIALIZING DOG P OBJECT -*-" << std::endl;

	Dog *p = new Dog();

	p->setBrain(0, "Testing copies");
	p->setBrain(1, "I want to sleep");

	Dog temp1 = *p;
	Dog temp2(*p);

	std::cout << std::endl << "-*- DELETING DOG P OBJECT -*-" << std::endl;

	delete p;

	std::cout << std::endl;
	std::cout << "Temp1 index0: " << temp1.getBrain(0) << std::endl;
	std::cout << "Temp1 index1: " << temp1.getBrain(1) << std::endl;
	std::cout << "Temp1 type: " << temp1.getType() << std::endl;

	std::cout << std::endl;
	std::cout << "Temp2 index0: " << temp2.getBrain(0) << std::endl;
	std::cout << "Temp2 index1: " << temp2.getBrain(1) << std::endl;
	std::cout << "Temp2 type: " << temp2.getType() << std::endl;

	std::cout << std::endl;
	temp1.setBrain(0, "New idea");
	temp1.setBrain(1, "Sleep");

	std::cout << "New temp3" << std::endl;
	Dog temp3 = temp1;

	std::cout << std::endl;
	std::cout << "Temp3 index0: " << temp3.getBrain(0) << std::endl;
	std::cout << "Temp3 index1: " << temp3.getBrain(1) << std::endl;
	std::cout << "Temp3 type: " << temp3.getType() << std::endl;
	std::cout << std::endl;
}
