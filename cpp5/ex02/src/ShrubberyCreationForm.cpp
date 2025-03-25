#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

// CONSTRUCTOR AND DESTRUCTOR

ShubberyCreationForm::ShubberyCreationForm()
    : AForm("ShubberyCreationForm", 25, 5), _target("") {}

ShubberyCreationForm::ShubberyCreationForm(const std::string & target)
    : AForm("ShubberyCreationForm", 25, 5), _target(target) {}

ShubberyCreationForm::ShubberyCreationForm(const ShubberyCreationForm &s)
    : AForm(s), _target(s._target) {}

ShubberyCreationForm &ShubberyCreationForm::operator=(const ShubberyCreationForm &s){
    if (this != &s) {
        setTarget(s.getTarget());
        setSigned(s.boolCheckSign()); 
    }
	return *this;
}

ShubberyCreationForm::~ShubberyCreationForm() {}

// MEMBER FUNCTIONS

void ShubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkRequirementsToExecute(executor);
    std::cout << "Is working" << std::endl;

}

const std::string & ShubberyCreationForm::getTarget() const {
    return _target;
}

void ShubberyCreationForm::setTarget(const std::string& target) {
    this->_target = target;
}

