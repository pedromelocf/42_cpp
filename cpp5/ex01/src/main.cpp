#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main() {

	std::cout << "------------> TEST 1 <------------" << std::endl;
	try {
		Bureaucrat weber("Weber", 120);
		std::cout << weber << std::endl;
		Form certification("SF", 120, 25);
		std::cout << certification << std::endl;
		certification.beSigned(weber);
		std::cout << certification << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "------------> TEST 2 <------------" << std::endl;
	try {
		Bureaucrat max("Max", 120);
		std::cout << max << std::endl;
		Form certification("SX", 151, 25);
		std::cout << certification << std::endl;
		certification.beSigned(max);
		std::cout << certification << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "------------> TEST 3 <------------" << std::endl;
	try {
		Bureaucrat john("John", 5);
		std::cout << john << std::endl;
		Form certification("SD", -1, 25);
		std::cout << certification << std::endl;
		certification.beSigned(john);
		std::cout << certification << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "------------> TEST 4 <------------" << std::endl;
	try {
		Bureaucrat leonard("Leonard", 43);
		std::cout << leonard << std::endl;
		Form certification("SP", 42, 25);
		std::cout << certification << std::endl;
		certification.beSigned(leonard);
		std::cout << certification << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "------------> TEST 5 <------------" << std::endl;
	try {
		Bureaucrat felix("Felix", 5);
		std::cout << felix << std::endl;
		Form certification("SND", 4, 3);
		std::cout << certification << std::endl;
		certification.beSigned(felix);
		std::cout << certification << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "------------> TEST 6 <------------" << std::endl;
	try {
		Bureaucrat keyla("Keyla", 23);
		std::cout << keyla << std::endl;
		Form certification("SX", 130, 25);
		std::cout << certification << std::endl;
		certification.beSigned(keyla);
		std::cout << certification << std::endl;
		certification.beSigned(keyla);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "------------> TEST 7 <------------" << std::endl;
	try {
		Form certification("SX", 55, 23);
		std::cout << certification << std::endl;
		Form warrant(certification);
		std::cout << warrant << std::endl;

	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "------------> TEST 8 <------------" << std::endl;
	try {
		Form certification("SX", 130, 25);
		Form warrant("Arrest", 12, 100);
		Bureaucrat george("Geoger", 1);
		std::cout << certification << std::endl;
		certification.beSigned(george);
		std::cout << certification << std::endl;
		std::cout << warrant << std::endl;
		warrant = certification;
		std::cout << warrant << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
} 