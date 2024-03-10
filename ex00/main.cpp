#include <iostream>
#include "Convert.hpp"

int main(int argc, char **argv)
{
    cout << "using namespace std를 지우시오\n";

    if (argc != 2) {
        cout << "usage: ./" << argv[0] << " char literal | decimal notation\n";
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}