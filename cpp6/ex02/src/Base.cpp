#include "../includes/Base.hpp"

Base::~Base() {}

Base * generate(void) {

    std::srand(time(0));
    switch (rand() % 3 + 1) {

        case 1: 
            std::cout << "A" <<std::endl;
            return (Base*) new A();
            break;
    
        case 2:
            std::cout << "B" << std::endl;
            return (Base*) new B();
            break;

        case 3:
            std::cout << "C" << std::endl;
            return (Base*) new C();
            break;
        
        default:
            return NULL;
    }
}

void identify(Base* p) {

    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;

    else if (dynamic_cast<B*>(p) != NULL )
        std::cout << "B" << std::endl;

    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {

    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
        
    } catch(const std::exception & e) {
        std::cerr << e.what() << '\n';
    }

    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;

    } catch(const std::exception & e) {
        std::cerr << e.what() << '\n';
    }
    
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;

    } catch(const std::exception & e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Unkown type" << std::endl;
}