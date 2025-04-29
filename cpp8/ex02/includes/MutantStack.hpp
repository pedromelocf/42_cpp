#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack: public std::stack<T> {

	public:
		MutantStack () {};
		MutantStack (const MutantStack & copy) : std::stack<T>(copy) {};	

		MutantStack & operator= (const MutantStack & copy) {
			if (this != & copy)
				std::stack<T>::operator=(copy);
			return *this;
		};
		~MutantStack () {};
		typedef typename std::deque<T>::iterator iterator;

		iterator begin () { return this->c.begin(); };
		iterator end () { return this->c.end(); };

};


#endif