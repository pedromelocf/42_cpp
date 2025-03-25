#include "../includes/AForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

// CONSTRUCTOR AND DESTRUCTOR

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r)
    : AForm(r), _target(r._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &r){
    if (this != &r) {
        setTarget(r.getTarget());
        setSigned(r.boolCheckSign()); 
    }
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// MEMBER FUNCTIONS

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    checkRequirementsToExecute(executor);
    std::cout << "Birl, making drilling noises..... " << std::endl;
    
    if (rand() % 2 == 1)
        std::cout << getTarget() << " robotomy completed sucessfully." << std::endl;
    else
        std::cout << getTarget() << " robotomy failed." << std::endl;
}

const std::string & RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::setTarget(const std::string& target) {
    this->_target = target;
}

