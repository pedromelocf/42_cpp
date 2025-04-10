#include "../includes/TypeConverter.hpp"

TypeConverter::TypeConverter() {}

TypeConverter::TypeConverter(const TypeConverter & t) {
    static_cast<void>(&t);
}

TypeConverter &TypeConverter::operator= (const TypeConverter & t) {
    static_cast<void>(&t);
    return *this;
}

TypeConverter::~TypeConverter() {}

int TypeConverter::typecheck (std::string & s) {
    static_cast<void>(&s);
    return 0;
}

char TypeConverter::convertchar (std::string & s) {
    static_cast<void>(&s);
}

int TypeConverter::convertint (std::string & s) {
    static_cast<void>(&s);
}

double TypeConverter::convertdouble (std::string & s) {
    static_cast<void>(&s);
}

float TypeConverter::convertfloat (std::string & s) {
    static_cast<void>(&s);
}

float TypeConverter::convertpseudofloat (std::string & s) {

}

double TypeConverter::convertpseudodouble (std::string & s) {

}

void TypeConverter::displayconversion (char c) {

    std::cout << "char: '" << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void TypeConverter::displayconversion (int i) {

    std::cout << "char: '" << static_cast<int>(i) << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void TypeConverter::displayconversion (float f) {

    std::cout << "char: '" << static_cast<char>(f) << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void TypeConverter::displayconversion (double d) {

    std::cout << "char: '" << static_cast<char>(d) << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << std::endl;
    std::cout << "double: " << d << std::endl;
}

void TypeConverter::displaypseudo (float f) { //fix

    std::cout << "char: '" << static_cast<char>(f) << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << static_cast<float>(f) << std::endl;
    std::cout << "double: " << f << std::endl;
}

void TypeConverter::displaypseudo (double d) { //fix

    std::cout << "char: '" << static_cast<char>(d) << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << std::endl;
    std::cout << "double: " << d << std::endl;
}
