#include "../includes/PresidentialPardonForm.hpp"

// CONSTRUCTOR AND DESTRUCTOR

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("") {
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
	}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p)
	: AForm(p), _target(p._target) {
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p){
	if (this != &p) {
		setTarget(p.getTarget());
		setSigned(p.boolCheckSign()); 
	}
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Default destructor called" << std::endl;
}

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

