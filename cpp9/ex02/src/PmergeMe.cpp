#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	_vector = other._vector;
	_deque = other._deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fordJohnsonSortVector(int pair_size) {

	while (( _vector.size() / 2) > pair_size ) {

		int chunks = _vector.size() / pair_size;
		for (int i = 0; chunks > 0 ; i += pair_size, --chunks) {

			int k = i + pair_size / 2 - 1;
			int l = i + pair_size - 1;
			if (_vector.at(k) > _vector.at(l)) {

				std::vector<int> temp;
				if (chunks == 1 && _vector.size() % pair_size != 0 ) {

					temp.insert(temp.end(), _vector.begin() + k + 1 , _vector.end());
					_vector.erase(_vector.begin() + k + 1, _vector.end());
				}
				std::swap_ranges(_vector.begin(), _vector.begin() + k, _vector.begin() + l);
				_vector.insert(_vector.end() - 1, temp.begin(), temp.end());
				temp.clear();
			}
		}
		fordJohnsonSortVector(pair_size * 2);
	}

	int chunks = _vector.size() / pair_size;
	for (int i = 0; chunks > 0 ; i += pair_size, --chunks) {

		std::vector<int> temp, main, pend, jacobsthal_numbers;
		int vector_size = _vector.size();
		for (int m = 0 ; vector_size > m; ++m ) {

			if (chunks == 1 && _vector.size() % pair_size != 0 )
				temp.insert(temp.end(), _vector.begin() + m, _vector.end());
			else if (m == 0 || m % 2 != 1)
				main.insert(main.end(), _vector.begin() + m, _vector.begin() + m + pair_size);
			else
				pend.insert(pend.end(), _vector.begin() + m, _vector.begin() + m + pair_size );
		}
		_vector.clear();
		jacobsthal_numbers = generateJacobsthalIndices(pend.size());
		int prev_jacobsthal = jacobsthal_numbers[0];
		for (int p = 1;; p++) {

			int curr_jacobsthal = jacobsthal_numbers[p];
			int jacobsthal_dif = curr_jacobsthal - prev_jacobsthal;
			if (jacobsthal_diff > static_cast<int>(pend.size()))
				break;
			int insertion_times = jacobsthal_diff;
			while(insertion_times > 0) {
				insertion_times--;
			}
			prev_jacobsthal = curr_jacobsthal;
		}
		while (pend.size() > 0 ) {
			//insert from end to begin of pend to main.
		}
		//copy from temp to main;
		//copy from main to _vector;
		// main.clear(); temp.clear();
	}
}

void PmergeMe::fordJohnsonSortDeque(int pair_size) {
}

bool PmergeMe::checkSequence() {

}

std::vector<int> generateJacobsthalIndices(size_t size) {

	std::vector<int> jacobsthal = {1};
	int j1 = 1, j2 = 0;
	while (jacobsthal.back() < static_cast<int>(size)) {

		int next = j1 + 2 * j2;
		jacobsthal.push_back(next);
		j2 = j1;
		j1 = next;
	}
	return jacobsthal;
}