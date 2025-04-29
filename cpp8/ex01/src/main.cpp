#include "../includes/Span.hpp"
#include <cstdlib>

int main () {

	srand (time(NULL));
	int random = 0;

	std::cout << "TEST 1: Span 5 Numbers" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << std::endl << "TEST 2: Span 5 Random Numbers" << std::endl;

	std::vector<int> vector_int;

	for (long unsigned int i = 0; i < 5; i++) {
		random = rand() % 500 + 1;
		vector_int.push_back(random);
	}
	
	Span sp1 = Span(5);

	try {
		sp1.addNumber(vector_int.begin(), vector_int.end());
	} catch (const std::exception & e) {
		std::cerr << e.what()  << std::endl;
	}

	try {
		std::vector<int>:: iterator it = vector_int.begin();
		std::vector<int>:: iterator ite = vector_int.end();

		for (; it != ite; ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	} catch (const std:: exception & e) {
		std::cerr << e.what()  << std::endl;
	}

	try {
		int longestSpan = sp1.longestSpan();
		std::cout << "Longest Span: " << longestSpan << std::endl;
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		int shortestSpan = sp1.shortestSpan();
		std::cout << "Shortest Span: " << shortestSpan << std::endl;
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "TEST 3: Span 10000 Random Numbers" << std::endl;

	std::vector<int> vector_int1;

	for (long unsigned int i = 0; i < 10000; i++) {
		random = rand();
		vector_int1.push_back(random);
	}
	
	Span sp2 = Span(10000);

	try {
		sp2.addNumber(vector_int1.begin(), vector_int1.end());
	} catch (const std::exception & e) {
		std::cerr << e.what()  << std::endl;
	}

	try {
		int longestSpan = sp2.longestSpan();
		std::cout << "Longest Span: " << longestSpan << std::endl;
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		int shortestSpan = sp2.shortestSpan();
		std::cout << "Shortest Span: " << shortestSpan << std::endl;
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "TEST 4: Span 100000 Random Numbers" << std::endl;

	std::vector<int> vector_int2;

	for (long unsigned int i = 0; i < 100000; i++) {
		random = rand();
		vector_int2.push_back(random);
	}
	
	Span sp3 = Span(100000);

	try {
		sp3.addNumber(vector_int2.begin(), vector_int2.end());
	} catch (const std::exception & e) {
		std::cerr << e.what()  << std::endl;
	}

	try {
		int longestSpan = sp3.longestSpan();
		std::cout << "Longest Span: " << longestSpan << std::endl;
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		int shortestSpan = sp3.shortestSpan();
		std::cout << "Shortest Span: " << shortestSpan << std::endl;
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}