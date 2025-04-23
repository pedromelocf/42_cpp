#include "Array.hpp"

int main()
{
    std::cout << "   TEST 1: STRING ARRAY " << std:: endl;
    Array<std::string> arr_str(2);
    arr_str[0] = "1";
    arr_str[1] = "2";

    std::cout << "arr_str[0] = '" << arr_str[0] << "'; arr_str[1] = '" << arr_str[1] << "'" << std::endl;

    std::cout << std::endl << "   TEST 2: OUT OF RANGE " << std:: endl;
    try {
        std::cout << arr_str[2] << std::endl; 
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "   TEST 3:  OUT OF RANGE " << std:: endl;
    try {
        std::cout << arr_str[-1] << std::endl; 
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "   TEST 4: GET ARRAY SIZE " << std:: endl;
    std::cout << "Array size: "<< arr_str.getsize() << std::endl;

    std::cout << std::endl << "   TEST 5: COPY CONSTRUCTOR " << std:: endl;
    Array<std::string> arr_str_cpy(arr_str);

    std::cout << "Pre change orig:   " << "    arr_str[0] = '" << arr_str[0] << "';        arr_str[1] = '" << arr_str[1] << "'" << std::endl;
    std::cout << "Pre change cpy:    " << "arr_str_cpy[0] = '" << arr_str_cpy[0] << "';    arr_str_cpy[1] = '" << arr_str_cpy[1] << "'" << std::endl << std::endl;
    
    arr_str[0] = "3";
    arr_str[1] = "4";

    std::cout << "Post change orig:  " << "    arr_str[0] = '" << arr_str[0] << "';        arr_str[1] = '" << arr_str[1] << "'" << std::endl;
    std::cout << "Post change cpy:   " << "arr_str_cpy[0] = '" << arr_str_cpy[0] << "';    arr_str_cpy[1] = '" << arr_str_cpy[1] << "'" << std::endl;

    std::cout << std::endl << "   TEST 6: ASSIGNMENT OPERATOR " << std:: endl;
    Array<std::string> arr_str_assign(5);
    arr_str_assign = arr_str;

    std::cout << "Pre change orig:   " << "       arr_str[0] = '" << arr_str[0] << "';        arr_str[1] = '" << arr_str[1] << "'" << std::endl;
    std::cout << "Pre change cpy:    " << "arr_str_assign[0] = '" << arr_str_assign[0] << "'; arr_str_assign[1] = '" << arr_str_assign[1] << "'" << std::endl << std::endl;
    
    arr_str[0] = "5";
    arr_str[1] = "6";

    std::cout << "Post change orig:  " << "       arr_str[0] = '" << arr_str[0] << "';        arr_str[1] = '" << arr_str[1] << "'" << std::endl;
    std::cout << "Post change cpy:   " << "arr_str_assign[0] = '" << arr_str_assign[0] << "'; arr_str_assign[1] = '" << arr_str_assign[1] << "'" << std::endl;

    // std::cout << std::endl << "   TEST 7: CONST OVERLOAD " << std:: endl;
    // const Array<int> const_arr(36) ;
    // std::cout << const_arr[0] << std::endl;

    arr_str.deletearray();
    arr_str_assign.deletearray();
    arr_str_cpy.deletearray();
    // const_arr.deletearray();

    return 0;
}