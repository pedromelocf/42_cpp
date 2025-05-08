#include "../includes/RPN.hpp"
#include <iostream>

int main (int argc, char **argv) {

    if (argc != 2){
        std::cerr << "Invalid number of arguments. Usage=> './RPN \"expression\"'" << std::endl;
        return 1;
    }

    if (RPN::checkExpression(argv[1]) == false){
        std::cerr << "Error" << std::endl;
        return 2;
    }

    RPN::processExpression(argv[1]);

    return 0;
}

