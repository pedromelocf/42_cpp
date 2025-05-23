#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> to_sort) {
	_vector = to_sort;
	_pair_size = 2;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	_vector = other._vector;
	_deque = other._deque;
	_pair_size = other._pair_size;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
		_pair_size = other._pair_size;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fordJohnsonSortVector() {

	mergeVector();
	insertionVector();
}

void PmergeMe::mergeVector() {

	while ((_vector.size() / 2) > _pair_size) {

        size_t chunks = _vector.size() / _pair_size;
        for (size_t i = 0; chunks > 0; i += _pair_size, --chunks) {

            size_t mid = i + _pair_size / 2;
            size_t end = i + _pair_size;
            if (_vector[mid - 1] > _vector[end - 1]) 
                std::swap_ranges(_vector.begin() + i, _vector.begin() + mid, _vector.begin() + mid );
        }
		_pair_size *= 2;
	}
	_pair_size /= 2;
}

void PmergeMe::insertionVector() {
	
	while (true) {

		size_t i = 0;
		std::vector<int> temp, main, pend, jacobsthal_numbers;

		for (;i + _pair_size <= _vector.size(); i += _pair_size) {

			std::vector<int> chunk(_vector.begin() + i, _vector.begin() + i + _pair_size);
			if (i == 0) 
				main.insert(main.end(), chunk.begin(), chunk.end());
			else if (((i / _pair_size) % 2) == 1) 
				main.insert(main.end(), chunk.begin(), chunk.end());
			else 
				pend.insert(pend.end(), chunk.begin(), chunk.end());
		}

		if (_vector.size() % _pair_size != 0) {
			size_t leftover = _vector.size() - i;
			temp.insert(temp.end(), _vector.end() - leftover, _vector.end());
		}

			// _vector.clear();
			// jacobsthal_numbers = generateJacobsthalIndices(pend.size());
			// int prev_jacobsthal = jacobsthal_numbers[0];
			// for (int p = 1 ; p < jacobsthal_numbers.size(); p++) {

			// 	int curr_jacobsthal = jacobsthal_numbers[p];
			// 	int jacobsthal_dif = curr_jacobsthal - prev_jacobsthal;
			// 	if (jacobsthal_dif > static_cast<int>(pend.size()))
			// 		break;
			// 	int insertion_times = jacobsthal_dif;
			// 	while(insertion_times > 0) {
			// 		insertion_times--;
			// 	}
			// 	prev_jacobsthal = curr_jacobsthal;
			// }
			// while (pend.size() > 0 ) {

			// 	size_t value_to_insert = pend.back();
			// 	pend.pop_back();
			// 	main.insert(std::lower_bound(main.begin(), main.end(), value_to_insert), value_to_insert);
			// }
			// main.insert(main.end(), temp.begin(), temp.end());
			// _vector = main;
			if (_pair_size == 1)
				break;
			_pair_size /= 2;
	}
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