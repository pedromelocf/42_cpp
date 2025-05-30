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
		PmergeMe(std::deque<int> to_sort);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	fordJohnsonSortVector();
		void	mergeVector();
		void	insertionVector();
};

long jacobsthal_number(long n);

#endif
