#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {
    // Constructor implementation
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    // Copy constructor implementation
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        // Copy assignment implementation
    }
    return *this;
}

PmergeMe::~PmergeMe() {
    // Destructor implementation
}

void PmergeMe::fordJohnsonSort() {

    fordJohnsonSortVector(2);
    // fordJohnsonSortDeque();
}

void PmergeMe::fordJohnsonSortVector(int pair_size) {

    while (( _vector.size() / 2) > pair_size ) {

        int chunks = _vector.size() / pair_size;
        for (int i = 0; chunks > 0 ; i += pair_size, --chunks) {

            int k = i + pair_size / 2 - 1;
            int l = i + pair_size - 1;
            if (_vector.at(k) > _vector.at(l)) {

                std::vector<int> temp;
                if (chunks == 1 && _vector.size() % pair_size != 0 ) {

                    temp.insert(temp.begin(), _vector.begin() + k, _vector.end());
                    _vector.erase(_vector.begin() + k, _vector.end());
                }
                std::swap_ranges(_vector.begin(), _vector.begin() + k, _vector.begin() + l);
                _vector.insert(_vector.begin() + l, temp.begin(), temp.end());
                temp.clear();
            }
        }
        fordJohnsonSortVector(pair_size * 2);
    }

    // start Jacobsthal numbers;

    while (pair_size != 2) {


    }

}

void PmergeMe::fordJohnsonSortDeque() {

    mergeSortDeque(2);
    insertionSortDeque();
}

void PmergeMe::mergeSortDeque(int pair_size) {}

void PmergeMe::insertionSortDeque() {}

bool PmergeMe::checkSequence() {}