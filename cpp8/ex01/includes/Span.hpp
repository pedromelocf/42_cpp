#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

class Span {

	private:
		unsigned int _maxSize;
		std::vector<int> _storedNumbers;

	public:
		Span();
		Span(unsigned int N);
		// Span(const Span & other);
		// Span & operator=(const Span & other);
		~Span();

		void addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end);
		int shortestSpan();
		int longestSpan();

		unsigned int get_maxSize();
		std::vector<int> const get_storedNumbers();
};
#endif 
