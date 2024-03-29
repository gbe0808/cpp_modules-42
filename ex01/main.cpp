#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Argument error\n";
        return 1;
    }

    RPN *rpn;
    try {
        rpn = RPN::get_instance(argv[1]);
    } catch (const char *error) {
        std::cout << "Error: " << error << '\n';
        return 1;
    }

    try {
        int res = rpn->execute();
        std::cout << res << '\n';
    } catch (const char *error) {
        std::cout << error << '\n';
    }

    rpn->release_instance();
    return 0;
}