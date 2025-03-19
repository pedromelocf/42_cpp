#include "../includes/GradeTooLowException.hpp"

const char *GradeTooLowException::what() const throw() {
    return "Grade Too Low";
}