#pragma once

#include <string>

using namespace std;

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

    static unsigned short check_type(string &literal);

public:
    static void convert(string literal);

};
