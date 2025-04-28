#include "../includes/MutantStack.hpp"

int main () {

	MutantStack<int> mstack_int;

	mstack_int.push(5);
	mstack_int.push(17);

	std::cout << mstack_int.top() << std::endl;

	mstack_int.pop();

	std::cout << mstack_int.size() << std::endl;

	mstack_int.push(3);
	mstack_int.push(5);
	mstack_int.push(737);
	mstack_int.push(0);

	MutantStack<int>::iterator it = mstack_int.begin();
	MutantStack<int>::iterator ite = mstack_int.end();

	++it;
	--it;

	while (it != ite) {

		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack_int);
	return 0;

}