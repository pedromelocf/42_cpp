#include "../includes/Span.hpp"

Span::Span() : _maxSize(0) , _storedNumbers(0) {}

Span::Span(unsigned int N) : _maxSize(N), _storedNumbers(0) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _storedNumbers(other._storedNumbers) {}

Span & Span::operator=(const Span & other) {
	if (this != & other) {
		_maxSize = other._maxSize;
		_storedNumbers = other._storedNumbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end) {

	for (unsigned int i = 0; it_begin != it_end; i++, it_begin++) {
		if (i >= this->_maxSize)
			throw std::out_of_range("Attempt to add element failed: Maxsize reached");
		_storedNumbers.push_back(*it_begin);
	}
}

void Span::addNumber(int number) {
	if (this->_storedNumbers.size() >= this->_maxSize)
		throw std::out_of_range("Attempt to add element failed: Maxsize reached");
	_storedNumbers.push_back(number);
}

int Span::shortestSpan() {
	
	if (get_maxSize() <= 1)
		throw std::out_of_range("Invalid number of elements.");

	std::vector<int> sorted = _storedNumbers;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator it = sorted.begin();
	std::vector<int>::iterator ite = sorted.end();

	int shortestSpan = INT_MAX;
	for (; it != ite - 1 ; ++it) {
		if (*(it + 1) - *it < shortestSpan)
			shortestSpan = *(it + 1) - *it;
	}

	return shortestSpan;
}

int Span::longestSpan() {

	if (get_maxSize() <= 1)
		throw std::out_of_range("Invalid number of elements.");

	std::vector<int> sorted = _storedNumbers;
	std::sort(sorted.begin(), sorted.end());

	return *(sorted.end() - 1) - *sorted.begin();
}

std::vector<int> const Span::get_storedNumbers() { return _storedNumbers; }

unsigned int Span::get_maxSize()  { return _maxSize; };
