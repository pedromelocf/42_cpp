#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
#include <algorithm>
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
        double				_vectorTime;
        double				_dequeTime;
		
		bool	validateInput(const std::string& input);
		void	parseArgs(char **argv);

		void	fordJohnsonSortVector(std::vector<int>& arr);
		void	fordJohnsonSortDeque(std::deque<int>& arr);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void	processArgs(char **argv);
		void 	displayElapsedTime();

};

#endif
