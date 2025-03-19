#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <Bureaucrat.hpp>

class Form {
    private:
        const std::string& _name;
        bool _isSigned;
        const unsigned short int _gradeToSign;
        const unsigned short int _gradeToExec;
    
    public:
        Form();
        Form(const std::string& name, unsigned short int gradeToSign, unsigned short int _gradeToExec);
        Form(const Form& f);
        Form& operator= (const Form& f); 
        ~Form();

        const std::string& getName() const;
        bool boolCheckSign() const;
        unsigned short int reqGradeToSign() const;
        unsigned short int reqGradeToExec() const;
        void beSigned(Bureaucrat& b);
};

#endif