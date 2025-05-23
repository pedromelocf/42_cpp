#include "../includes/PmergeMe.hpp"

int main () {

    int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13,7};
    std::vector<int> myVector(arr, arr + sizeof(arr) / sizeof(arr[0]));

    PmergeMe pmerge(myVector);
    pmerge.fordJohnsonSortVector();

    return 0;
}