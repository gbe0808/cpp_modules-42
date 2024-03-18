#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Convert.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) 
{
    (void) ref;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
    (void) ref;
    return *this;
}

unsigned short ScalarConverter::check_type(std::string &literal)
{
    if (literal.length() == 1 && ((32 <= literal[0] && literal[0] < '0') || ('9' < literal[0] && literal[0] < 127)))
        return CHAR;
    if (literal.find('.') != std::string::npos) {
        int dot_num = 0;
        if (!(literal[0] == '-' || literal[0] == '+' || std::isdigit(literal[0])))
            return ERROR_TYPE;
        for (size_t i = 1; i < literal.length(); i++) {
            if (std::isdigit(literal[i]))
                continue;
            if (literal[i] == '.')
                ++dot_num;
            else if (i == literal.length() - 1 && literal[i] == 'f' && dot_num == 1)
                return FLOAT;
            else
                return ERROR_TYPE;
        }
        if (dot_num == 1)
            return DOUBLE;
        return ERROR_TYPE;
    }
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
        return FLOAT;
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
        return DOUBLE;
    
    if (!(literal[0] == '-' || literal[0] == '+' || std::isdigit(literal[0])))
        return ERROR_TYPE;
    for (size_t i = 1; i < literal.length(); i++) {
        if (!std::isdigit(literal[i]))
            return ERROR_TYPE;
    }

    return INT;
}

void ScalarConverter::convert(std::string literal)
{
    const unsigned short type = check_type(literal);

    std::cout << "type: " << type << '\n';

    if (type == ERROR_TYPE) {
        std::cout << "Error: invalid input" << std::endl;
        return;
    }

    if (type == CHAR) {
        char ch = literal[0];
        std::cout << "char: '" << ch << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(ch) << std::endl;
        std::cout << "float: " << static_cast<float>(ch) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
        return;
    }

    else if (type == INT) {
        int num = std::strtod(literal.c_str(), NULL);
        char ch = static_cast<char>(num);
        
        if (32 <= ch && ch < 127)
            std::cout << "char: '" << ch << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << num << std::endl;
        std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
    }

    else if (type == FLOAT) {
        if (!std::isdigit(literal[1])) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << literal << std::endl;
            literal.pop_back();
            std::cout << "double: " << literal << std::endl;
            return;
        }

        std::cout.precision(std::numeric_limits<float>::digits10);
        float num = std::strtof(literal.c_str(), NULL);
        char ch = static_cast<char>(num);
        
        if (std::isprint(ch))
            std::cout << "char: '" << ch << '\'' << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        
        std::cout << "int: " << static_cast<int>(num) << std::endl;
        double int_part;
        if (!std::modf(num, &int_part)) {
            std::cout << "float: " << num << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
        }
        else {
            std::cout << "float: " << num << 'f' << std::endl;
            std::cout << "double: " << static_cast<double>(num) << std::endl;
        }
    }

    else if (type == DOUBLE) {
        if (!std::isdigit(literal[1])) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << literal << 'f' << std::endl;
            std::cout << "double: " << literal << std::endl;
            return;
        }

        std::cout.precision(std::numeric_limits<double>::digits10);
        double num = std::strtod(literal.c_str(), NULL);
        char ch = static_cast<char>(num);
        
        if (std::isprint(ch))
            std::cout << "char: '" << ch << '\'' << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        
        std::cout << "int: " << static_cast<int>(num) << std::endl;
        
        double int_part;
        if (!std::modf(num, &int_part)) {
            std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
            std::cout << "double: " << num << ".0" << std::endl;
        }
        else {
            std::cout << "float: " << static_cast<float>(num) << 'f' << std::endl;
            std::cout << "double: " << num << std::endl;
        }
    }
}
