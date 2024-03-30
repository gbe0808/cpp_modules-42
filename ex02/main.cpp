#include <iostream>
#include <sstream>
#include "PmergeMe.hpp"

int main()
{
    std::string str = "1 2 3 4 214748364 5";
    std::istringstream ss(str);
    int num;
    while (ss >> num) {
        std::cout << "num: " << num << '\n';
    }

    if (!ss.eof()) {
        std::cout << "fail?\n";
    }
    return 0;
}
