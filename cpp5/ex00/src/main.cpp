#include "../includes/Bureaucrat.hpp"
#include "../includes/GradeTooHighException.hpp"
#include "../includes/GradeTooLowException.hpp"

int main() {

    std::cout << "----------Low Score test----------" << std::endl;

    Bureaucrat adailton("Adailton", 150);
    try
    {
        std::cout << adailton.getName() << std::endl;
        std::cout << adailton.getGrade() << std::endl;
        adailton.incrementGrade();
        std::cout << adailton.getGrade() << std::endl;
        adailton.decrementGrade();
        std::cout << adailton.getGrade() << std::endl;
        adailton.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl; 
    }

    std::cout << "----------High Score test----------" << std::endl;

    Bureaucrat roberto("Roberto", 1);
    try
    {
        std::cout << roberto.getName() << std::endl;
        std::cout << roberto.getGrade() << std::endl;
        roberto.decrementGrade();
        std::cout << roberto.getGrade() << std::endl;
        roberto.incrementGrade();
        std::cout << roberto.getGrade() << std::endl;
        roberto.incrementGrade();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl; 
    }

    std::cout << "----------Copy constructors test----------" << std::endl;

    Bureaucrat jose(roberto);
    try {
        std::cout << jose.getName() << std::endl;
        std::cout << jose.getGrade() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl; 
    }

    jose = adailton;
    try {
        std::cout << jose.getName() << std::endl;
        std::cout << jose.getGrade() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl; 
    }

} 