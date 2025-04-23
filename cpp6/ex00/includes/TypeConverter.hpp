#ifndef TYPE_CONVERTER_HPP
# define TYPE_CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
#include <iomanip>

class TypeConverter {

    private:
        TypeConverter();
        TypeConverter(const TypeConverter & t);
        TypeConverter& operator= (const TypeConverter & t);
        ~TypeConverter();

    public:
        static int typecheck (std::string & s);

        static char convertchar (std::string & s);
        static int convertint (std::string & s);
        static double convertdouble (std::string & s);
        static float convertfloat (std::string & s);

        static void displayconversion(char c);
        static void displayconversion(int i);
        static void displayconversion(float f);
        static void displayconversion(double d);
        static void displaypseudo(float f);
        static void displaypseudo(double d);

        static bool checkdigits (std::string & s);
};

#endif