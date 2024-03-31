#include <iostream>
#include <sstream>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cout << "usage: ./" << argv[0] << "args ...\n";
        return 1;
    }

    PmergeMe *pmergeMe = NULL;

    try {
        pmergeMe = PmergeMe::get_instance(argc, argv);
    } catch (const char *error) {
        std::cout << error << '\n';
        return 1;
    }

    size_t a = PmergeMe::Jacobsthal[0];
    a += 1;
    (void) a;
    PmergeMe::execute();
    PmergeMe::release_instance();
    return 0;
}
