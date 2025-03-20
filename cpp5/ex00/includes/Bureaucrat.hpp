#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat 
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat& operator= (const Bureaucrat& b); 
        ~Bureaucrat();const

        std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        void operator<< (Bureaucrat b);
};

std::ostream& operator<< ( std::ostream& os, const Bureaucrat& b);

#endif