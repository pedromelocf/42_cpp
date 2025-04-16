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

    if (s == "nanf" || s == "+inff" || s == "-inff")
        return 4;
    if (s == "nan" || s == "+inf" || s == "-inf")
        return 5;

    bool validliteral = TypeConverter::checkdigits(s);
    if (validliteral == true) {

        if (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
            return 0;
        if (s.find('.') != std::string::npos && s.find('f') != std::string::npos)
            return 3;
        if (s.find('.') != std::string::npos)
            return 2;
        return 1;
    }
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
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void TypeConverter::displayconversion (float f) {

    if (std::isprint(static_cast<char>(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void TypeConverter::displayconversion (double d) {

    if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void TypeConverter::displaypseudo (float f) {

    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void TypeConverter::displaypseudo (double d) {

    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" <<std::endl;
    std::cout << "double: " << d << std::endl;
}

bool TypeConverter::checkdigits (std::string & s) {

    int dotCount = 0;
    int fCount = 0;
    long unsigned int i = 0;

    for (i = 0; i < s.length(); i++) {

        if (std::isdigit(s[i]))
            continue;
        else if (s[i] == '.') {
            dotCount++;
            if (dotCount > 1)
                return false;
        }
        else if (s[i] == 'f') {
            fCount++;
            if (fCount > 1 || i != s.length() - 1)
                return false;
        }
        else if (s[i] == '+' || s[i] == '-') {
            if (i != 0)
                return false;
        }
        else if (s.length() == 1 && std::isprint(s[0]))
            return true;
        else
            return false;
    }

    if ((s[i - 1] == '.' && s.length() != 1) || (fCount == 1 && dotCount == 0) || (s[i - 1] == 'f' && s[i - 2] == '.'))
        return false;

    return true;
}
