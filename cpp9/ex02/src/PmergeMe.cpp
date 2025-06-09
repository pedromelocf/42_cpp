#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	_vector = other._vector;
	_deque = other._deque;
	_vectorTime = other._vectorTime;
	_dequeTime = other._dequeTime;
	_pairSizeVector = other._pairSizeVector;
	_pairSizeDeque = other._pairSizeDeque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
		_pairSizeVector = other._pairSizeVector;
		_pairSizeDeque = other._pairSizeDeque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::validateInput(const std::string &input) {
	if (input.empty())
		return (false);

	for (size_t i = 0; i < input.length(); ++i) {
		if (!isdigit(input[i]))
			return (false);
	}

	try {
		long num = std::atol(input.c_str());
		if (num < 0 || num > INT_MAX)
			return (false);
	} catch(const std::exception &e) {
		return (false);
	}

	return (true);
}

void PmergeMe::parseArgs(char **argv) {
	_vector.clear();
	_deque.clear();

	std::set<int> uniqueValues;
	int i = 1;
	while (argv[i])
	{
		std::string arg = argv[i];
		std::istringstream iss(arg);
		std::string token;

		while (iss >> token)
		{
			if (!validateInput(token))
				throw std::runtime_error(std::string("Error"));
			int num = atoi(token.c_str());
			if (uniqueValues.find(num) != uniqueValues.end())
				continue ;
			uniqueValues.insert(num);
			_vector.push_back(num);
			_deque.push_back(num);
		}
		i++;
	}
	_pairSizeVector = 2;
	_pairSizeDeque = 2;

	if (_vector.empty())
		throw std::runtime_error(std::string("Error"));
}

void PmergeMe::processArgs(char **argv) {

	parseArgs(argv);

	std::cout << "Before: " ;
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	clock_t start = std::clock();
	fordJohnsonSortVector();
	clock_t end = std::clock();
	_vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = std::clock();
	fordJohnsonSortDeque();
	end = std::clock();
	_dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Vector After: " ;
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Deque After:  " ;
	for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}

void PmergeMe::displayElapsedTime() {

	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector: "
		<< std::fixed << std::setprecision(5) << _vectorTime << " us" << std::endl;

	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque: "
		<< std::fixed << std::setprecision(5) << _dequeTime << " us" << std::endl << std::endl;
}

void PmergeMe::checkSorting() {

	bool sorted = true;
	for (size_t i = 1; i < _vector.size(); ++i) {
		if (_vector[i - 1] > _vector[i]) {
			sorted = false;
			break;
		}
	}
	std::cout << (sorted ? "Vector is sorted." : "Vector is NOT sorted.") << std::endl;

	sorted = true;
	for (size_t i = 1; i < _deque.size(); ++i) {
		if (_deque[i - 1] > _deque[i]) {
			sorted = false;
			break;
		}
	}
	std::cout << (sorted ? "Deque is sorted." : "Deque is NOT sorted.") << std::endl;
}

void PmergeMe::fordJohnsonSortVector() {

	mergeVector();
	insertionVector();
}

void PmergeMe::mergeVector() {

	while ((_vector.size() / 2) > _pairSizeVector) {

        size_t chunks = _vector.size() / _pairSizeVector;
        for (size_t i = 0; chunks > 0; i += _pairSizeVector, --chunks) {

            size_t mid = i + _pairSizeVector / 2;
            size_t end = i + _pairSizeVector;
            if (_vector[mid - 1] > _vector[end - 1])
                std::swap_ranges(_vector.begin() + i, _vector.begin() + mid, _vector.begin() + mid );
        }
		_pairSizeVector *= 2;
	}
	_pairSizeVector /= 2;
}

void PmergeMe::insertionVector() {

	while (true) {

		size_t i = 0;
		std::vector<int> temp, main, pend;

		for (;i + _pairSizeVector <= _vector.size(); i += _pairSizeVector) {

			std::vector<int> chunk(_vector.begin() + i, _vector.begin() + i + _pairSizeVector);
			if (((i / _pairSizeVector) % 2) == 1 || i == 0) {
				
				int pend_value_to_find = chunk.back();
				std::vector<int>::iterator insert_chunk_pos = main.end();

				for (size_t j = 0; j + _pairSizeVector <= main.size(); j += _pairSizeVector) {

					int current_chunk_last = *(main.begin() + j + _pairSizeVector - 1);
					if (pend_value_to_find < current_chunk_last) {
						insert_chunk_pos = main.begin() + j;
						break;
					}
				}
				main.insert(insert_chunk_pos, chunk.begin(), chunk.end());
			}
			else
				pend.insert(pend.end(), chunk.begin(), chunk.end());
		}

		if (_vector.size() % _pairSizeVector != 0) {
			size_t leftover = _vector.size() - i;
			temp.insert(temp.end(), _vector.end() - leftover, _vector.end());
		}

		int prev_jacobsthal = jacobsthal_number(1);
		int inserted_numbers = 0;
		int pend_size = static_cast<int>(pend.size() / _pairSizeVector);
		for (size_t p = 2;; p++) {

			int curr_jacobsthal = jacobsthal_number(p);
			int jacobsthal_dif = curr_jacobsthal - prev_jacobsthal;
			if (jacobsthal_dif > pend_size)
				break;
			int insertion_times = jacobsthal_dif;
			while (insertion_times) {

				std::vector<int>::iterator chunk_begin = pend.begin() + ((insertion_times - 1) * _pairSizeVector);
				std::vector<int>::iterator chunk_end = chunk_begin + _pairSizeVector;
				std::vector<int> chunk(chunk_begin, chunk_end);

				int pend_value_to_find = chunk.back();
				std::vector<int>::iterator chunk_main_last_value, insert_chunk_pos = main.begin();

				for(long unsigned int j = 0, i = 0; i < main.size() / _pairSizeVector; j += _pairSizeVector, i++) {

					chunk_main_last_value = main.begin() + j + _pairSizeVector - 1;
					if (pend_value_to_find <= *chunk_main_last_value) {
   						insert_chunk_pos = main.begin() + j;
    					break;
					}
				}
				main.insert(insert_chunk_pos, chunk.begin(), chunk.end());
				pend.erase(chunk_begin, chunk_end);
				insertion_times--;
			}
			prev_jacobsthal = curr_jacobsthal;
			inserted_numbers += jacobsthal_dif;
			pend_size -= jacobsthal_dif;
		}

		for (ssize_t i = pend_size - 1; i >= 0; i--) {
			
			std::vector<int>::iterator chunk_begin = pend.end() - _pairSizeVector;
			std::vector<int>::iterator chunk_end = pend.end();
			std::vector<int> chunk(chunk_begin, chunk_end);

			int pend_value_to_find = chunk.back();
			std::vector<int>::iterator chunk_main_last_value, insert_chunk_pos = main.begin();

			for(long unsigned int j = 0, i = 0; i < main.size() / _pairSizeVector; j += _pairSizeVector, i++) {

				chunk_main_last_value = main.begin() + j + _pairSizeVector - 1;
				if (pend_value_to_find <= *chunk_main_last_value) {
   					insert_chunk_pos = main.begin() + j;
    				break;
				}
			}
			main.insert(insert_chunk_pos, chunk.begin(), chunk.end());
			pend.erase(chunk_begin, chunk_end);
		}
		pend.clear();
		main.insert(main.end(), temp.begin(), temp.end());
		if (_pairSizeVector == 1) {
			_vector = main;
			break;
		}
		_pairSizeVector /= 2;
	}
}

void PmergeMe::fordJohnsonSortDeque() {
	mergeDeque();
	insertionDeque();
}

void PmergeMe::mergeDeque() {

	while ((_deque.size() / 2) > _pairSizeDeque) {

        size_t chunks = _deque.size() / _pairSizeDeque;
        for (size_t i = 0; chunks > 0; i += _pairSizeDeque, --chunks) {

            size_t mid = i + _pairSizeDeque / 2;
            size_t end = i + _pairSizeDeque;
            if (_deque[mid - 1] > _deque[end - 1])
                std::swap_ranges(_deque.begin() + i, _deque.begin() + mid, _deque.begin() + mid );
        }
		_pairSizeDeque *= 2;
	}
	_pairSizeDeque /= 2;
}

void PmergeMe::insertionDeque() {

	while (true) {

		size_t i = 0;
		std::deque<int> temp, main, pend;

		for (;i + _pairSizeDeque <= _deque.size(); i += _pairSizeDeque) {

			std::deque<int> chunk(_deque.begin() + i, _deque.begin() + i + _pairSizeDeque);
			if (((i / _pairSizeDeque) % 2) == 1 || i == 0) {
				
				int pend_value_to_find = chunk.back();
				std::deque<int>::iterator insert_chunk_pos = main.end();

				for (size_t j = 0; j + _pairSizeDeque <= main.size(); j += _pairSizeDeque) {

					int current_chunk_last = *(main.begin() + j + _pairSizeDeque - 1);
					if (pend_value_to_find < current_chunk_last) {
						insert_chunk_pos = main.begin() + j;
						break;
					}
				}
				main.insert(insert_chunk_pos, chunk.begin(), chunk.end());
			}
			else
				pend.insert(pend.end(), chunk.begin(), chunk.end());
		}

		if (_deque.size() % _pairSizeDeque != 0) {
			size_t leftover = _deque.size() - i;
			temp.insert(temp.end(), _deque.end() - leftover, _deque.end());
		}

		int prev_jacobsthal = jacobsthal_number(1);
		int inserted_numbers = 0;
		int pend_size = static_cast<int>(pend.size() / _pairSizeDeque);
		for (size_t p = 2;; p++) {

			int curr_jacobsthal = jacobsthal_number(p);
			int jacobsthal_dif = curr_jacobsthal - prev_jacobsthal;
			if (jacobsthal_dif > pend_size)
				break;
			int insertion_times = jacobsthal_dif;
			while (insertion_times) {

				std::deque<int>::iterator chunk_begin = pend.begin() + ((insertion_times - 1) * _pairSizeDeque);
				std::deque<int>::iterator chunk_end = chunk_begin + _pairSizeDeque;
				std::deque<int> chunk(chunk_begin, chunk_end);

				int pend_value_to_find = chunk.back();
				std::deque<int>::iterator chunk_main_last_value, insert_chunk_pos = main.begin();

				for(long unsigned int j = 0, i = 0; i < main.size() / _pairSizeDeque; j += _pairSizeDeque, i++) {

					chunk_main_last_value = main.begin() + j + _pairSizeDeque - 1;
					if (pend_value_to_find <= *chunk_main_last_value) {
   						insert_chunk_pos = main.begin() + j;
    					break;
					}
				}
				main.insert(insert_chunk_pos, chunk.begin(), chunk.end());
				pend.erase(chunk_begin, chunk_end);
				insertion_times--;
			}
			prev_jacobsthal = curr_jacobsthal;
			inserted_numbers += jacobsthal_dif;
			pend_size -= jacobsthal_dif;
		}

		for (ssize_t i = pend_size - 1; i >= 0; i--) {
			
			std::deque<int>::iterator chunk_begin = pend.end() - _pairSizeDeque;
			std::deque<int>::iterator chunk_end = pend.end();
			std::deque<int> chunk(chunk_begin, chunk_end);

			int pend_value_to_find = chunk.back();
			std::deque<int>::iterator chunk_main_last_value, insert_chunk_pos = main.begin();

			for(long unsigned int j = 0, i = 0; i < main.size() / _pairSizeDeque; j += _pairSizeDeque, i++) {

				chunk_main_last_value = main.begin() + j + _pairSizeDeque - 1;
				if (pend_value_to_find <= *chunk_main_last_value) {
   					insert_chunk_pos = main.begin() + j;
    				break;
				}
			}
			main.insert(insert_chunk_pos, chunk.begin(), chunk.end());
			pend.erase(chunk_begin, chunk_end);
		}
		pend.clear();
		main.insert(main.end(), temp.begin(), temp.end());
		if (_pairSizeDeque == 1) {
			_deque = main;
			break;
		}
		_pairSizeDeque /= 2;
	}
}

long jacobsthal_number(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }