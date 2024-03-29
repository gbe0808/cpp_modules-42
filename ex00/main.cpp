#include <exception>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cout << "Error: could not open file.\n";
        return 1;
    }
    if (argc > 2) {
        std::cout << "Error: too many arguments.\n";
        return 1;
    }

    BitcoinExchange *instance;
    try {
        instance = BitcoinExchange::get_instance(argv[1]);
    } catch (const char *error) {
        std::cout << "Error: " << error << '\n';
        return 1;
    }

    instance->exchange();
    instance->release_instance();

    return 0;
}
