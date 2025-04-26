#include "../includes/Span.hpp"

int main () {

    std::vector<int> vector_int;

    for (long unsigned int i = 0; i <= 99999; i++) {
        vector_int.push_back(i);
    }

    Span sp = Span(100000);
    try {
        sp.addNumber(vector_int.begin(), vector_int.end());
    } catch (const std::exception & e) {
        std::cerr << e.what()  << std::endl;
    }

}