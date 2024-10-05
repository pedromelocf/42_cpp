#include "Zombie.hpp"

Zombie::Zombie ( std::string name ) {
    this->_name = name;
}


Zombie::~Zombie ( void ) {

    std::cout << this->_name;
    std::cout << " called destructor" << std::endl;

}

void    Zombie::announce( void ) {

    std::cout << this->_name;
    std::cout << ":  BraiiiiiiinnnzzzZ..." << std::endl;

}