#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

// CONSTRUCTOR AND DESTRUCTOR

AForm::AForm()
	: _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Bureaucrat::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm &f)
	: _name(f.getName()), _isSigned(f.boolCheckSign()), _gradeToSign(f.reqGradeToSign()), _gradeToExec(f.reqGradeToExec()) {}

AForm &AForm::operator=(const AForm &f) {
	if (this != &f) {
		_isSigned = f.boolCheckSign();
	}
	return *this;
}

AForm::~AForm() {}

// MEMBER FUNCTIONS

const std::string& AForm::getName() const{
	return _name;
}

bool AForm::boolCheckSign() const {
	return _isSigned;
}

int AForm::reqGradeToSign() const {
	return _gradeToSign;
}

int AForm::reqGradeToExec() const {
	return _gradeToExec;
}

void AForm::setSigned(bool isSigned) {
	_isSigned = isSigned;
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() <= this->reqGradeToSign() && this->boolCheckSign() == false) {
		_isSigned = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	else if (this->boolCheckSign() == true && b.getGrade() > this->reqGradeToSign())
		std::cout << b.getName() << " couldn´t sign " << this->getName() <<" because form is already signed and grade is to low."  << std::endl;
	else if (this->boolCheckSign() == true)
		std::cout << b.getName() << " couldn´t sign " << this->getName() <<" because form is already signed."  << std::endl;
	else
		std::cout << b.getName() << " couldn´t sign " << this->getName() <<" because grade is to low."  << std::endl;
}

void AForm::checkRequirementsToExecute(Bureaucrat const & executor) const{
	if (boolCheckSign() == false)
		throw FormNotSignedException();
	if (executor.getGrade() >= reqGradeToExec())
		throw GradeTooLowException();
}

// EXCEPTION

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low to execute form.";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed.";
}

// OVERLOAD << TO STDOUT

std::ostream& operator<< ( std::ostream& os, const AForm& f) {
	if (f.boolCheckSign() == true)
		os << f.getName() << ", grade to sign " << f.reqGradeToSign() << ", grade to execute " << f.reqGradeToExec() << " is signed" << ".";
	else
		os << f.getName() << ", grade to sign " << f.reqGradeToSign() << ", grade to execute " << f.reqGradeToExec() << " is not signed" << ".";

	return os;
}
