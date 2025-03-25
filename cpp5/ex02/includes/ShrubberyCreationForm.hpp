#ifndef SHUBBERYCREATIONFORM
#define SHUBBERYCREATIONFORM

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShubberyCreationForm : public AForm {

    private:
        std::string _target;
    public:
        ShubberyCreationForm();
        ShubberyCreationForm(const std::string& target);
        ShubberyCreationForm(const ShubberyCreationForm& s);
        ShubberyCreationForm& operator= (const ShubberyCreationForm& s);
        ~ShubberyCreationForm();

        const std::string& getTarget() const;
        void setTarget(const std::string& target);
        void execute(Bureaucrat const & executor) const;
};

#endif