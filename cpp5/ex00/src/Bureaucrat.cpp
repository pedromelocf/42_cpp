#include "../includes/Bureaucrat.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Bureaucrat::Bureaucrat()
    : _name(""), _grade(150) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name) {
    this->setGrade(grade);
    std::cout << "Bureaucrat Named constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
    : _name(b.getName()), _grade(b.getGrade()) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b){
    if (this != &b) {
        this->setGrade(b.getGrade());
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

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::setGrade(int grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

void Bureaucrat::incrementGrade() {

    this->setGrade(this->getGrade() - 1);
    std::cout << "Grade incremented" << std::endl;
}

void Bureaucrat::decrementGrade() {

    this->setGrade(this->getGrade() + 1);
    std::cout << "Grade decremented" << std::endl;
}

// EXCEPTION 

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

// OVERLOAD << TO STDOUT

std::ostream& operator<< ( std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
