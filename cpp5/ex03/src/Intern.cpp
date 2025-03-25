#include "../includes/Intern.hpp"

Intern::Intern() {
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern& i) {
    *this = i;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern:: operator=(const Intern& i) {
    if (this != &i)
        std::cout << "Intern copy assignment constructor called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor constructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string & formName, const std::string & targetName) {

    std::string array[3] = {"presidential pardon","robotomy request", "shrubbery creation"};

    for (int i = 0; i < 3; i++) {
        if (formName.compare(array[i]) == 0) {
            std::cout << "Intern creates " << array[i] << " form." <<std::endl;
            return objectBuilder(targetName, i);
        }
    }
    std::cerr << "Error: " << formName << " form does not exist. " << std::endl;
    return NULL;
}

AForm* Intern::objectBuilder(const std::string & targetName, int i) {
    switch (i) 
    {
        case 0: 
            return new PresidentialPardonForm(targetName);
        case 1:
            return new RobotomyRequestForm(targetName);
        case 2:
            return new ShrubberyCreationForm(targetName);
        default:
            return NULL; 
    }
}