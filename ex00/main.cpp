#include <exception>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cout << "Error: could not open file.\n";
        return 0;
    }
    if (argc > 2) {
        std::cout << "Error: too many arguments.\n";
        return 0;
    }

    BitcoinExchange *instance;
    try {
        instance = BitcoinExchange::getBitcoinExchange(argv[1]);
    } catch (const char *error) {
        std::cout << "Error: " << error << '\n';
        return 0;
    }

    instance->exchange();
    instance->releaseInstance();

    return 0;
}
