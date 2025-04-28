#include "../includes/easyfind.hpp"

#include <deque>
#include <list>
#include <vector>

int main () {

	std::vector<int> vector_int(0);
	std::deque<int> deque_int(0);
	std::list<int> list_int(0);

	for (long unsigned int i = 1; i <= 5; i++) {
		vector_int.push_back(i);
	}

	for (long unsigned int i = 12; i <= 16; i++) {
		deque_int.push_back(i);
	}

	for (long unsigned int i = 4; i <= 8; i++) {
		list_int.push_back(i);
	}

	std::cout << "-----> VECTOR INT  : " ;
	std::vector<int>::iterator vector_it = vector_int.begin();
	for (; vector_it != vector_int.end(); vector_it++) {
		std::cout << "[" << *vector_it << "] ";
	}

	std::cout << std::endl << std::endl << "*--------- TEST 1: VECTOR INT FIND[3] ---------*" << std::endl;
	try {
		int value = easyfind(vector_int, 3);
		std::cout << "Number found : " << value << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl  << "*--------- TEST 2: VECTOR INT FIND[6]---------*" << std::endl;
	try {
		int value = easyfind(vector_int, 6);
		std::cout << "Number found : " << value << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "-----> DEQUE INT  : ";

	std::deque<int>::iterator deque_it = deque_int.begin();
	for (; deque_it != deque_int.end(); deque_it++) {
		std::cout << "[" << *deque_it << "] ";
	}

	std::cout << std::endl << std::endl << "*--------- TEST 3: DEQUE INT FIND[15] --------*" << std::endl;
	try {
		int value = easyfind(deque_int, 15);
		std::cout << "Number found : " << value << std::endl;
	} catch(const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "*--------- TEST 4: DEQUE INT FIND[3]---------*" << std::endl;
	try {
		int value = easyfind(deque_int, 3);
		std::cout << "Number found : " << value << std::endl;
	} catch(const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "-----> LIST INT   : ";

	std::list<int>::iterator list_it = list_int.begin();
	for (; list_it != list_int.end(); list_it++) {
		std::cout << "[" << *list_it << "] ";
	}

	std::cout << std::endl << std::endl << "*--------- TEST 5: LIST INT FIND[7]---------*" << std::endl;
	try {
		int value = easyfind(list_int, 7);
		std::cout << "Number found : " << value << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "*--------- TEST 6: LIST INT FIND[9]---------*" << std::endl;
	try {
		int value = easyfind(list_int, 9);
		std::cout << "Number found : " << value << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

}