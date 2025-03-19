#include "../includes/Bureaucrat.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Bureaucrat::Bureaucrat()
    : _name(""), _grade(150) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned short int grade)
    : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    std::cout << "Bureaucrat Named constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
    : _name(b.getName()), _grade(b.getGrade()) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b){
    if (this != &b) {
        _name = b.getName();
        _grade = b.getGrade();
    }
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Default destructor called" << std::endl;
}

// MEMBER FUNCTIONS

const std::string& Bureaucrat::getName() const {
    return _name;
}


unsigned short int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {

    if (_grade - 1 == 0)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {

    if (_grade + 1 == 151)
        throw GradeTooLowException();
    _grade++;
}