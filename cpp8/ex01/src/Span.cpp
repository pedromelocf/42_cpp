#include "../includes/Span.hpp"

Span::Span() : _maxSize(0) , _storedNumbers(0) {}

Span::Span(unsigned int N) : _maxSize(N), _storedNumbers(N) {}

// Span::Span(const Span& other) {}

// Span& Span::operator=(const Span& other) {
//     if (this != &other) {
//         // Copy assignment implementation
//     }
//     return *this;
// }

Span::~Span() {}

void Span::addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end) {

    for (unsigned int i = 0; it_begin != it_end; i++, it_begin++) {
        if (i >= this->_maxSize){
            throw std::out_of_range("Attempt to add element failed: Maxsize reached");
        }
        _storedNumbers.push_back(*it_begin);
    }
}

int Span::shortestSpan() {
    
    if (get_maxSize() == 1)
        throw std::out_of_range("Invalid span size.");

    return 0;
}

int Span::longestSpan() {
    if (get_maxSize() == 1)
        throw std::out_of_range("Invalid span size.");
        
    return 0;
}

std::vector<int> const Span::get_storedNumbers() { return _storedNumbers; }

unsigned int Span::get_maxSize()  { return _maxSize; };
