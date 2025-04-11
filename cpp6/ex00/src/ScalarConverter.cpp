#include "../includes/ScalarConverter.hpp"
#include "../includes/TypeConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & s) {
    static_cast<void>(&s);
}

ScalarConverter &ScalarConverter::operator= (const ScalarConverter & s) {
    static_cast<void>(&s);
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert (const char * s) {

    std::string literal = s;
    int type = TypeConverter::typecheck(literal);

    switch (type) {

        case 0: {
            char c = TypeConverter::convertchar(literal);
            TypeConverter::displayconversion(c);
            break;
        }
        
        case 1:{

            int i = TypeConverter::convertint(literal);
            TypeConverter::displayconversion(i);
            break;
        }
        
        case 2:{

            double d = TypeConverter::convertdouble(literal);
            TypeConverter::displayconversion(d);
            break;
        }

        case 3: {

            float f = TypeConverter::convertfloat(literal);
            TypeConverter::displayconversion(f);
            break;
        }

        case 4: {

            float pf = TypeConverter::convertfloat(literal);
            TypeConverter::displaypseudo(pf);
            break;
        }

        case 5:{
            
            double pd = TypeConverter::convertdouble(literal);
            TypeConverter::displaypseudo(pd);
            break;
        }

        default:
            std::cout << "Invalid literal." << std::endl;
            break;
    }    
}