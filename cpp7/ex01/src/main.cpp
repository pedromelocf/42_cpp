#include "../includes/iter.hpp"

int main () {

    int arr_int[5] = {5, 3 , 1 , 2, 4};
    std::cout << "Array int pre: ";
    ::iter(arr_int, 5, printelement<int>);
    ::iter(arr_int, 5, increment<int>);
    std::cout << std::endl <<"Array int pos: ";
    ::iter(arr_int, 5, printelement<int>);
    std::cout << std::endl << std::endl;

    std::string arr_str[3] = {"test", "hello", "world"};
    std::cout << "Array string pre: ";
    ::iter(arr_str, 3,  printelement<std::string>);
    ::iter(arr_str, 3, uppercase<std::string>);
    std::cout << std::endl  << "Array string pos: ";
    ::iter(arr_str, 3,  printelement<std::string>);
    std::cout << std::endl;

    return 0;
}