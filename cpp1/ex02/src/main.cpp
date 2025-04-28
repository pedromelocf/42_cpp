#include "iostream"

int main (void) {

	std::string original = "HI THIS BRAIN";
	std::string* stringPTR = &original;
	std::string& stringREF = original;

	std::cout << &original << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << original << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;

}
