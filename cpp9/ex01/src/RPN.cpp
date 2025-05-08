#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	static_cast<void>(&other);
}

RPN& RPN::operator=(const RPN& other) {
	static_cast<void>(&other);
	return *this;
}

RPN::~RPN() {}

bool RPN::checkExpression(std::string const & expression) {

    std::string::const_iterator it = expression.begin();
    std::string::const_iterator ite = expression.end();

    if (expression.length() == 1 || std::isdigit(*ite) || !std::isdigit(*it) || expression.length() % 2 == 0)
        return false;
    it++;
    for (int i = 0; it != ite; ++it, ++i) {
        if (i % 2 == 0 && (*it) != ' ')
            return false;
        else if (i % 2 == 1 && (!std::isdigit(*it) && ((*it) != '+' && (*it) != '-' && (*it) != '/' && (*it) != '*')))
            return false;
    }
    return true;
}

void RPN::processExpression(std::string const & expression) {

    std::stack<int> stack;
    std::string::const_iterator it = expression.begin();
    std::string::const_iterator ite = expression.end();

    for (; it != ite; ++it) {
        int p1 = 0, p2 = 0;
        if (std::isdigit(*it)) 
            stack.push(std::atoi(&(*it)));

        else if ((*it) == '+' || (*it) == '-' || (*it) == '/' || (*it) == '*') {
            p1 = stack.top(); stack.pop();
            p2 = stack.top(); stack.pop();

            if ((*it) == '+') 
                stack.push(p2 + p1);
            else if ((*it) == '-')
                stack.push(p2 - p1);
            else if ((*it) == '/' && (*it) != 0)
                stack.push(p2 / p1);
            else if ((*it) == '*')
                stack.push(p2 * p1);            
        }
    }
    std::cout << "Result: " << stack.top() << std::endl;
    stack.pop();
}