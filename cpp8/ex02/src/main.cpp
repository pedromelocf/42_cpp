#include "../includes/MutantStack.hpp"
#include <list>

int main () {

    std::cout << "TEST 1: MutantStack int " << std::endl;

	MutantStack<int> mstack_int;

	mstack_int.push(5);
	mstack_int.push(17);

	std::cout << "mstack_int top: " << mstack_int.top() << std::endl;

	mstack_int.pop();

	std::cout << "mstack_int size: " << mstack_int.size() << std::endl;

	mstack_int.push(3);
	mstack_int.push(5);
	mstack_int.push(737);
	mstack_int.push(0);

	MutantStack<int>::iterator it = mstack_int.begin();
	MutantStack<int>::iterator ite = mstack_int.end();

	++it;
	--it;

    std::cout << "mstack_int elements: ";

	while (it != ite) {

		std::cout << *it << " ";
		++it;
	}

    std::cout << std::endl << std::endl << "TEST 2: List int" << std::endl;

    std::list<int> list_int;

	list_int.push_back(5);
	list_int.push_back(17);

	std::cout << "list_int top: " << list_int.back() << std::endl;

	list_int.pop_back();

	std::cout << "list_int size: " << list_int.size() << std::endl;

	list_int.push_back(3);
	list_int.push_back(5);
	list_int.push_back(737);
	list_int.push_back(0);

    std::list<int>::iterator it_list = list_int.begin();
    std::list<int>::iterator ite_list = list_int.end();

    std::cout << "list_int elements: ";

	while (it_list != ite_list) {

		std::cout << *it_list << " ";
		++it_list;
	}

    std::cout << std::endl << std::endl << "TEST 3: Constructors" << std::endl;

    MutantStack<std::string> mstack_str;

    mstack_str.push("Hello");

    MutantStack<std::string> mstack_str_cpy(mstack_str);

    std::cout << "mstack_str: " << mstack_str.top() << std::endl; 
    std::cout << "mstack_str_cpy: " << mstack_str_cpy.top() << std::endl << std::endl; 

    mstack_str_cpy.pop();
    mstack_str_cpy.push("World");

    std::cout << "mstack_str: " << mstack_str.top() << std::endl; 
    std::cout << "mstack_str_cpy: " << mstack_str_cpy.top() << std::endl << std::endl; 

    MutantStack<std::string> mstack_str_cpy_operator = mstack_str_cpy;

    std::cout << "mstack_str_cpy: " << mstack_str_cpy.top() << std::endl; 
    std::cout << "mstack_str_cpy_operator: " << mstack_str_cpy_operator.top() << std::endl; 

    mstack_str_cpy_operator.pop();
    mstack_str_cpy_operator.push("C++");
    
    std::cout << std::endl << "mstack_str_cpy: " << mstack_str_cpy.top() << std::endl; 
    std::cout << "mstack_str_cpy_operator: " << mstack_str_cpy_operator.top() << std::endl; 
    
	return 0;

}