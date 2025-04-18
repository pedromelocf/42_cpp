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
    std::cout << std::endl << std::endl;

    std::string * arr_null = NULL;
    ::iter(arr_null, 3,  printelement<std::string>);

    Data arr_obj[2] = {Data("Hello", 1), Data("World", 2)};
    std::cout << "Array objects pre: ";
    ::iter(arr_obj, 2, printelement<Data>);
    ::iter(arr_obj, 2, increment<Data>);
    std::cout << std::endl <<"Array objects pos: ";
    ::iter(arr_obj, 2, printelement<Data>);
    std::cout << std::endl;

    return 0;
}