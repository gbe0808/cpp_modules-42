#include <iostream>
#include "Convert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "usage: ./" << argv[0] << " char literal | decimal notation\n";
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}