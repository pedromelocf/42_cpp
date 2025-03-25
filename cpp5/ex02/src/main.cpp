#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main() {

    std::cout << "------------> TEST 1 <------------" << std::endl;
    try {
        PresidentialPardonForm one("home");

        std::cout << one.getName() << std::endl;
        std::cout << one.reqGradeToExec() << std::endl;
        std::cout << one.reqGradeToSign() << std::endl;
        std::cout << one.getTarget() << std::endl;

        Bureaucrat Pedro("Pedro", 4);
        one.beSigned(Pedro);
        Pedro.executeForm(one);
        
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // std::cout << std::endl << "------------> TEST 2 <------------" << std::endl;
    // try {
        
    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // std::cout << std::endl << "------------> TEST 3 <------------" << std::endl;
    // try {

    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // std::cout << std::endl << "------------> TEST 4 <------------" << std::endl;
    // try {

    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // std::cout << std::endl << "------------> TEST 5 <------------" << std::endl;
    // try {

    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // std::cout << std::endl << "------------> TEST 6 <------------" << std::endl;
    // try {

    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // std::cout << std::endl << "------------> TEST 7 <------------" << std::endl;
    // try {

    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // std::cout << std::endl << "------------> TEST 8 <------------" << std::endl;
    // try {

    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }
} 