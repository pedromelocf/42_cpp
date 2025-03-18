#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat 
{
    private:
        std::string _name;
        unsigned short int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, unsigned short int grade);
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat& operator= (const Bureaucrat& b); 
        ~Bureaucrat();const

        std::string& getName() const;
        unsigned short int getGrade() const;

        void incrementGrade();
        void decrementGrade();
};

#endif