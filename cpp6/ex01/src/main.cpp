#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main () {

    Data data("Pedro", 26);

    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Age: " << data.age << std::endl << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "raw: " << raw << std::endl << std::endl;

    Data* deserialized = Serializer::deserialize(raw);
    
    assert (deserialized == &data && "Object and deserialized must have the same address!");
    
    std::cout << "Object       address: " << &data << std::endl;
    std::cout << "Deserialized   value: " << deserialized << std::endl;
    std::cout << "Deserialized address: " << &deserialized << std::endl << std::endl;

    std::cout << "Deserialized Name: " << deserialized->name << std::endl;
    std::cout << "Deserialized Age: " << deserialized->age << std::endl << std::endl;
    std::cout << "Object Name: " << data.name << std::endl;
    std::cout << "Object Age: " << data.age << std::endl;

}