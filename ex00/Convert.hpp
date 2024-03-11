#pragma once

#include <string>

class ScalarConverter
{
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

    enum e_type {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        ERROR_TYPE
    };

    static unsigned short check_type(std::string &literal);

public:
    static void convert(std::string literal);

};
