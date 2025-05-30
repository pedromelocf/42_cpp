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
		std::vector<int> temp, main, pend;

		for (;i + _pair_size <= _vector.size(); i += _pair_size) {

			std::vector<int> chunk(_vector.begin() + i, _vector.begin() + i + _pair_size);
			if (i == 0 || ((i / _pair_size) % 2) == 1)
				main.insert(main.end(), chunk.begin(), chunk.end());
			else 
				pend.insert(pend.end(), chunk.begin(), chunk.end());
		}

		if (_vector.size() % _pair_size != 0) {
			size_t leftover = _vector.size() - i;
			temp.insert(temp.end(), _vector.end() - leftover, _vector.end());
		}

		int prev_jacobsthal = jacobsthal_number(1);
		int inserted_numbers = 0;
		int pend_size = static_cast<int>(pend.size() / _pair_size);
		for (size_t p = 2;; p++) {

			int curr_jacobsthal = jacobsthal_number(p);
			int jacobsthal_dif = curr_jacobsthal - prev_jacobsthal;
			if (jacobsthal_dif > pend_size)
				break;
			int insertion_times = jacobsthal_dif;
			while(insertion_times) {
				
				std::vector<int>::iterator chunk_begin = pend.begin() + ((insertion_times - 1) * _pair_size);
				std::vector<int>::iterator chunk_end = chunk_begin + _pair_size;
				std::vector<int> chunk(chunk_begin, chunk_end);
				int pend_value_to_find = chunk.back();
				std::vector<int>::iterator chunk_main_last_value, insert_chunk_pos = main.begin();
				for(long unsigned int j = 0, i = 0; i < main.size() / _pair_size; j += _pair_size, i++) {
					chunk_main_last_value = main.begin() + j + _pair_size - 1;
					if (pend_value_to_find > *chunk_main_last_value) 
						insert_chunk_pos = chunk_main_last_value + 1;
				}
				pend.erase(chunk_begin, chunk_end);
				main.insert(insert_chunk_pos, chunk.begin(), chunk.end());
				insertion_times--;
			}
			prev_jacobsthal = curr_jacobsthal;
			inserted_numbers += jacobsthal_dif;
			pend_size -= jacobsthal_dif;
		}

		for (ssize_t i = pend_size - 1; i >= 0; i--) {
			std::vector<int> chunk(pend.end() - _pair_size * i, pend.end() - (_pair_size * i) + _pair_size);
			int pend_value_to_find = chunk.back();
			std::vector<int>::iterator chunk_main_last_value, insert_chunk_pos = main.begin();
			for(long unsigned int j = 0, i = 0; i < main.size() / _pair_size; j += _pair_size, i++) {
				chunk_main_last_value = main.begin() + j + _pair_size - 1;
				if (pend_value_to_find > *chunk_main_last_value) 
					insert_chunk_pos = chunk_main_last_value + 1;
			}
			main.insert(insert_chunk_pos, chunk.begin(), chunk.end());
		}
		pend.clear();
		main.insert(main.end(), temp.begin(), temp.end());
		_vector = main;
		if (_pair_size == 1)
			break;
		_pair_size /= 2;
	}
}

// void PmergeMe::fordJohnsonSortDeque(int pair_size) {}

// bool PmergeMe::checkSequence() {}

long jacobsthal_number(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }
