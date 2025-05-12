#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {

	private:

		std::vector<int> _vector;
		std::deque<int> _deque;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	fordJohnsonSortVector(int pair_size);
		void	fordJohnsonSortDeque(int pair_size);
		static bool checkSequence();
};

std::vector<int> generateJacobsthalIndices(size_t limit);

#endif
