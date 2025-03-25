#include "../includes/PresidentialPardonForm.hpp"

// CONSTRUCTOR AND DESTRUCTOR

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 145, 137), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
    : AForm("PresidentialPardonForm", 145, 137), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p)
    : AForm(p), _target(p._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p){
    if (this != &p) {
        setTarget(p.getTarget());
        setSigned(p.boolCheckSign()); 
    }
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// MEMBER FUNCTIONS

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    checkRequirementsToExecute(executor);
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string & PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::setTarget(const std::string& target) {
    this->_target = target;
}

