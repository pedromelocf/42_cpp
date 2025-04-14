#ifndef DATA_HPP
# define DATA_HPP

#include <string>

struct Data {

    std::string name;
    int age;

    Data(const std::string& name, int age)
    : name(name), age(age) {}

};

#endif 
