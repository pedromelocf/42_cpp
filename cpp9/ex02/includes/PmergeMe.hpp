#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <limits.h>
#include <ctime>

class PmergeMe {

	private:
		std::vector<int>	_vector;
		std::deque<int> 	_deque;
		long unsigned int 	_pairSize;
        double				_vectorTime;
        double				_dequeTime;
		
		bool	validateInput(const std::string& input);
		void	parseArgs(char **argv);

		void	fordJohnsonSortVector();
		void	mergeVector();
		void	insertionVector();

		void	fordJohnsonSortDeque();
		void	mergeDeque();
		void	insertionDeque();

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void	processArgs(char **argv);
		void 	displayElapsedTime();

};

long jacobsthal_number(long n);

#endif
