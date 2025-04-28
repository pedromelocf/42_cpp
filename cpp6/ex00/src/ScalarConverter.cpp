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
			TypeConverter::displayconversion(static_cast<char>(TypeConverter::convertchar(literal)));
			break;
		}

		case 1:{
			TypeConverter::displayconversion(static_cast<int>(TypeConverter::convertint(literal)));
			break;
		}

		case 2:{
			TypeConverter::displayconversion(static_cast<double>(TypeConverter::convertdouble(literal)));
			break;
		}

		case 3: {
			TypeConverter::displayconversion(static_cast<float>(TypeConverter::convertfloat(literal)));
			break;
		}

		case 4: {
			TypeConverter::displaypseudo(static_cast<float>(TypeConverter::convertfloat(literal)));
			break;
		}

		case 5:{
			TypeConverter::displaypseudo(static_cast<double>(TypeConverter::convertdouble(literal)));
			break;
		}

		default:
			std::cout << "Invalid literal." << std::endl;
			break;
	}
}