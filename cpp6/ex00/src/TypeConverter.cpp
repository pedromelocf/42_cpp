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

    if (s.length() == 1 && std::isalpha(s[0])) 
        return 0;

    else if ()
    
    else if ()
    else if () 
    else if (s == "nanf" || s == "+inff" || s == "-inff")
        return 4;

    else if (s == "nan" || s == "+inf" || s == "-inf")
        return 5;

    return 6;
}

char TypeConverter::convertchar (std::string & s) {
    return s[0];
}

int TypeConverter::convertint (std::string & s) {
    int i;
    std::istringstream(s) >> i;
    return i;
}

double TypeConverter::convertdouble (std::string & s) {
    return atof(s.c_str());
}

float TypeConverter::convertfloat (std::string & s) {
    return atof(s.c_str());
}

void TypeConverter::displayconversion (char c) {

    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void TypeConverter::displayconversion (int i) {

    if (std::isprint(static_cast<char>(i)))
        std::cout << "char: '" << i << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void TypeConverter::displayconversion (float f) {

    std::cout << "char: '" << static_cast<char>(f) << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void TypeConverter::displayconversion (double d) {

    std::cout << "char: '" << static_cast<char>(d) << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void TypeConverter::displaypseudo (float f) {

    std::cout << "char: '" << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void TypeConverter::displaypseudo (double d) { 

    std::cout << "char: '" << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" <<std::endl;
    std::cout << "double: " << d << std::endl;
}