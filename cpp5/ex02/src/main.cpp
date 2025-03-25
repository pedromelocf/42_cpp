#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main() {

    std::cout << "------------> TEST 1 <------------" << std::endl;
    try {
        ShrubberyCreationForm shub("home");

        std::cout << "Name: " << shub.getName() << std::endl;
        std::cout << "Req grade to exec: " << shub.reqGradeToExec() << std::endl;
        std::cout << "Req grade to sign: " << shub.reqGradeToSign() << std::endl;
        std::cout << "Target: " << shub.getTarget() << std::endl;

        Bureaucrat Pedro("Pedro", 4);
        shub.beSigned(Pedro);
        Pedro.executeForm(shub);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 2 <------------" << std::endl;
    try {
        ShrubberyCreationForm shrub("home");
        Bureaucrat Joseph("Joseph", 149);
        shrub.beSigned(Joseph);
        Joseph.executeForm(shrub);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 3 <------------" << std::endl;
    try {
        PresidentialPardonForm presidential("Ford Prefect");

        std::cout << "Name: " << presidential.getName() << std::endl;
        std::cout << "Req grade to exec: " << presidential.reqGradeToExec() << std::endl;
        std::cout << "Req grade to sign: " << presidential.reqGradeToSign() << std::endl;
        std::cout << "Target: " << presidential.getTarget() << std::endl;

        Bureaucrat Alice("Alice", 52);
        Bureaucrat Pedro("Pedro", 4);
        presidential.beSigned(Alice);
        presidential.beSigned(Pedro);
        presidential.beSigned(Alice);
        presidential.beSigned(Pedro);
        presidential.execute(Alice);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 4 <------------" << std::endl;
    try {
        PresidentialPardonForm perfect("Ford Prefect");

        Bureaucrat Jane("Jane", 60);
        perfect.beSigned(Jane);
        perfect.execute(Jane);

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 5 <------------" << std::endl;
    try {
        RobotomyRequestForm robotomy("Lenny");

        std::cout << "Name: " << robotomy.getName() << std::endl;
        std::cout << "Req grade to exec: " << robotomy.reqGradeToExec() << std::endl;
        std::cout << "Req grade to sign: " << robotomy.reqGradeToSign() << std::endl;
        std::cout << "Target: " << robotomy.getTarget() << std::endl;

        Bureaucrat Daniel("Daniel", 2);
        robotomy.beSigned(Daniel);
        robotomy.execute(Daniel);
        robotomy.execute(Daniel);
        robotomy.execute(Daniel);
        robotomy.execute(Daniel);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 6 <------------" << std::endl;
    try {
        RobotomyRequestForm beeblebrox("Martin");
        Bureaucrat Frank("Frank", 1);
        
        beeblebrox.execute(Frank);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 7 <------------" << std::endl;
    try {
        ShrubberyCreationForm base("tree");
        Bureaucrat Lewis("Lewis", 3);
        base.beSigned(Lewis);
        std::cout << "Base target: " << base.getTarget() << std::endl;
        std::cout << "Base check is sign: " <<base.boolCheckSign() << std::endl;

        ShrubberyCreationForm copy(base);
        std::cout << "Copy target: " <<copy.getTarget() << std::endl;
        std::cout << "Copy check is sign: " << copy.boolCheckSign() << std::endl;
        
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 8 <------------" << std::endl;
    try {
        RobotomyRequestForm base("George");
        std::cout << "Base target: " << base.getTarget() << std::endl;

        RobotomyRequestForm copy("Alex");
        std::cout << "Copy target pre: " <<copy.getTarget() << std::endl;
        std::cout << "Copy check is signed pre: " << copy.boolCheckSign() << std::endl;

        Bureaucrat Smith("Smith", 32);
        base.beSigned(Smith);
        copy = base;
        std::cout << "Copy target after: " << copy.getTarget() << std::endl;
        std::cout << "Copy check is signed after: " << copy.boolCheckSign() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
} 