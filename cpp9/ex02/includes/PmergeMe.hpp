#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

class PmergeMe {

    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        void    fordJohnsonSort();

        void    fordJohnsonSortVector(int pair_size);

        void    fordJohnsonSortDeque();
        void    mergeSortDeque(int pair_size);
        void    insertionSortDeque();

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        static bool checkSequence();
};

#endif 
