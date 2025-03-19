#include "../includes/Form.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Form::Form()
    : _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string& name, unsigned short int gradeToSign, unsigned short int gradeToExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &f)
    : _name(f.getName()), _isSigned(f.boolCheckSign()), _gradeToSign(f.reqGradeToSign()), _gradeToExec(f.reqGradeToExec()) {
	std::cout << "Form Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &f){
    if (this != &f) {
        _isSigned = f.boolCheckSign();
    }
	std::cout << "Form Copy assignment operator called" << std::endl;
	return *this;
}

Form::~Form() {
	std::cout << "Form Default destructor called" << std::endl;
}

// MEMBER FUNCTIONS

const std::string& Form::getName() const{
    return _name;
}

bool Form::boolCheckSign() const {
    return _isSigned;
}

unsigned short int Form::reqGradeToSign() const {
    return _gradeToSign;
}

unsigned short int Form::reqGradeToExec() const {
    return _gradeToExec;
}

void Form::beSigned(Bureaucrat& b) {
    if (b.getGrade() <= this->reqGradeToSign() && this->boolCheckSign() == false) {
        this->_isSigned = true;
        std::cout << b.getName() << " signed " << this->getName() << std::endl;
    }
    else if (this->boolCheckSign() == true && b.getGrade() > this->reqGradeToSign())
        std::cout << b.getName() << " couldn´t sign " << this->getName() <<" because form is already signed and grade is to low."  << std::endl;
    else if (this->boolCheckSign() == true)
        std::cout << b.getName() << " couldn´t sign " << this->getName() <<" because form is already signed."  << std::endl;
    else 
        std::cout << b.getName() << " couldn´t sign " << this->getName() <<" because grade is to low."  << std::endl;
}