#ifndef GRADETOLOWEXECPTION_HPP
#define GRADETOLOWEXECPTION_HPP

#include <iostream>
#include <string>

class GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif