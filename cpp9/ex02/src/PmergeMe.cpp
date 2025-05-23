#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> to_sort) {
	_vector = to_sort;
}

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

void PmergeMe::fordJohnsonSortVector(long unsigned int pair_size) {

	while ((_vector.size() / 2) > pair_size) {

        size_t chunks = _vector.size() / pair_size;
        for (size_t i = 0; chunks > 0; i += pair_size, --chunks) {

            size_t mid = i + pair_size / 2;
            size_t end = i + pair_size;
            if (_vector[mid - 1] > _vector[end - 1]) 
                std::swap_ranges(_vector.begin() + i, _vector.begin() + mid, _vector.begin() + mid );
        }
		pair_size *= 2;
	}

	pair_size /= 2;

	while (pair_size != 2) {
		int chunks = _vector.size() / pair_size;
		for (size_t i = 0; chunks > 0; i += pair_size, --chunks) {

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
			for (int p = 1 ; p < jacobsthal_numbers.size(); p++) {

				int curr_jacobsthal = jacobsthal_numbers[p];
				int jacobsthal_dif = curr_jacobsthal - prev_jacobsthal;
				if (jacobsthal_dif > static_cast<int>(pend.size()))
					break;
				int insertion_times = jacobsthal_dif;
				while(insertion_times > 0) {
					insertion_times--;
				}
				prev_jacobsthal = curr_jacobsthal;
			}
			while (pend.size() > 0 ) {

				size_t value_to_insert = pend.back();
				pend.pop_back();
				main.insert(std::lower_bound(main.begin(), main.end(), value_to_insert), value_to_insert);
			}
			main.insert(main.end(), temp.begin(), temp.end());
			_vector = main;
			main.clear(); temp.clear(); pend.clear();
		}
	}
	pair_size /= 2;
}

// void PmergeMe::fordJohnsonSortDeque(int pair_size) {}

// bool PmergeMe::checkSequence() {}

std::vector<int> generateJacobsthalIndices(size_t size) {

	std::vector<int> jacobsthal(1,1);
	int j1 = 1, j2 = 0;
	while (jacobsthal.back() < static_cast<int>(size)) {

		int next = j1 + 2 * j2;
		jacobsthal.push_back(next);
		j2 = j1;
		j1 = next;
	}
	return jacobsthal;
}