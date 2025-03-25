#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {

    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& r);
        RobotomyRequestForm& operator= (const RobotomyRequestForm& r);
        ~RobotomyRequestForm();

        const std::string& getTarget() const;
        void setTarget(const std::string& target);
        void execute(Bureaucrat const & executor) const;
};

#endif