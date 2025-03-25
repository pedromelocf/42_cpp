#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

// CONSTRUCTOR AND DESTRUCTOR

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("") {
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
    }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s)
    : AForm(s), _target(s._target) {
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
    }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s){
    if (this != &s) {
        setTarget(s.getTarget());
        setSigned(s.boolCheckSign()); 
    }
    std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Default destructor called" << std::endl;
}

// MEMBER FUNCTIONS

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    
    checkRequirementsToExecute(executor);
    std::string filename = getTarget();
    filename.append("_shruberry");
    std::ofstream outfile(filename.c_str(), std::ios::trunc);
    if (!outfile.is_open()) {
        std::cerr << "File is not open" << std::endl;
        return;
    }
    outfile << " _ \n | | \n | |_ _ __ ___  ___ \n| __| '__/ _ \\/ _ \\ \n | |_| | |  __/  __/ \n \\__|_|  \\___|\\___| ";
    outfile.close();    
}

const std::string & ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::setTarget(const std::string& target) {
    this->_target = target;
}
