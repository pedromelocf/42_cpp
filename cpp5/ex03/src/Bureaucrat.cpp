#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Bureaucrat::Bureaucrat()
    : _name(""), _grade(150) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
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

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {

    if (_grade - 1 == 0)
        throw GradeTooHighException();
    std::cout << "Grade incremented" << std::endl;
    _grade--;
}

void Bureaucrat::decrementGrade() {

    if (_grade + 1 == 151)
        throw GradeTooLowException();
    std::cout << "Grade decremented" << std::endl;
    _grade++;
}

void Bureaucrat::executeForm(AForm const & f) {
    if (this->getGrade() <= f.reqGradeToSign() && f.boolCheckSign() == true) {
        f.execute(*this);
        std::cout << this->getName() << " executed " << f.getName() << std::endl;
    }
    else if (this->getGrade() <= f.reqGradeToSign())
        std::cout << f.getName() << " is not signed." << std::endl;
    else if (this->getGrade() > f.reqGradeToSign() && f.boolCheckSign() == false)
        std::cout << this->getName() << " does not have grade required to execute, and the form " << f.getName() << " is not signed." << std::endl;
    else
        std::cout << this->getName() << " does not have grade required to execute the form " << f.getName() << std::endl;
}

// EXCEPTION

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

void Bureaucrat::signForm(AForm& f) {
    f.beSigned(*this);
}

// OVERLOAD << TO STDOUT

std::ostream& operator<< ( std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
