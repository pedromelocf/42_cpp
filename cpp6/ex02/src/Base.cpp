#include "../includes/Base.hpp"

Base::~Base() {}

Base * generate(void) {

    static bool seed = false;

    if (!seed) {
        seed = true;
        std::srand(time(0));
    }

    switch (rand() % 3 + 1) {
        case 1:
            return (Base*) new A();
        case 2:
            return (Base*) new B();
        case 3:
            return (Base*) new C();
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
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << "A" << std::endl;
        return;
    } catch(const std::exception & e) {}

    try {
        static_cast<void>(dynamic_cast<B&>(p));
        std::cout << "B" << std::endl;
        return;
    } catch(const std::exception & e) {}

    try {
        static_cast<void>(dynamic_cast<C&>(p));
        std::cout << "C" << std::endl;
        return;
    } catch(const std::exception & e) {
        std::cerr << "Unknown type: " << e.what() << std::endl;
    }

}