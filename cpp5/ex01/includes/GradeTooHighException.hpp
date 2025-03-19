#ifndef GRADETOHIGHEXECPTION_HPP
#define GRADETOHIGHEXECPTION_HPP

#include <iostream>
#include <string>

class GradeTooHighException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif