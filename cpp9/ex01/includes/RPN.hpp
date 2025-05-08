#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN {

    private:

        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

    public:
        static bool checkExpression(std::string const & expression) ;
        static void processExpression(std::string const & expression);

};

#endif 
