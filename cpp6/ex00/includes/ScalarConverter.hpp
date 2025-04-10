#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter & s);
        ScalarConverter& operator= (const ScalarConverter & s);
        ~ScalarConverter();

    public:
        static void convert (const char * s);
};

#endif