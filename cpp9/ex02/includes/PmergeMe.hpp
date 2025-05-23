#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

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

std::vector<int> generateJacobsthalIndices(size_t limit);

#endif
