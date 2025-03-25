#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int main() {

    std::cout << "------------> TEST 1 <------------" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << "Req grade to exec: " << rrf->reqGradeToExec() << std::endl;
        std::cout << "Req grade to sign: " << rrf->reqGradeToSign() << std::endl;
        delete rrf;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 2 <------------" << std::endl;
    try {
        Intern someRandomIntern2;
        AForm* rrf2;

        rrf2 = someRandomIntern2.makeForm("presidential pardon", "Bender");
        std::cout << "Req grade to exec: " << rrf2->reqGradeToExec() << std::endl;
        std::cout << "Req grade to sign: " << rrf2->reqGradeToSign() << std::endl;
        delete rrf2;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 3 <------------" << std::endl;
    try {
        Intern someRandomIntern3;
        AForm* rrf3;

        rrf3 = someRandomIntern3.makeForm("shrubbery creation", "Bender");
        std::cout << "Req grade to exec: " << rrf3->reqGradeToExec() << std::endl;
        std::cout << "Req grade to sign: " << rrf3->reqGradeToSign() << std::endl;
        delete rrf3;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 4 <------------" << std::endl;
    try {
        Intern someRandomIntern4;
        AForm* rrf4;

        rrf4 = someRandomIntern4.makeForm("random", "Bender");
        if (rrf4)
            delete rrf4;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl << "------------> TEST 5 <------------" << std::endl;
    try {
        Intern brendon;
        AForm* CHS;
        Bureaucrat Justin("Justin", 32);
        Bureaucrat Harry("Harry", 3);

        CHS = brendon.makeForm("presidential pardon", "home");
        CHS->beSigned(Justin);
        CHS->beSigned(Harry);
        CHS->beSigned(Harry);
        CHS->execute(Harry);
        delete CHS;

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "------------> TEST 6 <------------" << std::endl;
    try {
        Intern someRandomIntern5;
        Intern someRandomIntern6(someRandomIntern5);
        someRandomIntern5 = someRandomIntern6;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

} 