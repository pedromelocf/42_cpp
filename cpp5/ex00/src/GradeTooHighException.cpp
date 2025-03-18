#include "../includes/GradeTooHighException.hpp"

const char *GradeTooHighException::what() const throw() {
    return "Grade Too High";
}