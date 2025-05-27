#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

class PmergeMe {

	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		long unsigned int _pair_size;

	public:
		PmergeMe();
		PmergeMe(std::vector<int> to_sort);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	fordJohnsonSortVector();
		// void	fordJohnsonSortDeque(int pair_size);
		// static bool checkSequence();
		void	mergeVector();
		void	insertionVector();
};

long jacobsthal_number(long n);
size_t find_chunk_insert_pos(const std::vector<int> main, const std::vector<int> chunk, size_t chunk_size);

#endif
