#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

    Zombie** zombie_array = new Zombie*[N];

    for (int i = 0; i < N; i++) {

        Zombie zombie_object( name );
        *zombie_array[i] = zombie_object;

    }

    return ( *zombie_array );

}