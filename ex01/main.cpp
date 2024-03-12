#include <iostream>
#include "iter.hpp"

void print_int(int &i)
{
    std::cout << i << ' ';
}

void multi_int(int &i)
{
    i = i * i;
}

void print_char(char &c)
{
    std::cout << c << ' ';
}

int main()
{
    int arr_int[5] = {1, 3, 5, 7, 9};
    char arr_char[5] = {'a', 'b', 'c', 'd', 'e'};

    ::iter(arr_int, 5, print_int);
    std::cout << std::endl;
    ::iter(arr_int, 5, multi_int);
    ::iter(arr_int, 5, print_int);
    std::cout << std::endl;
    ::iter(arr_char, 5, print_char);
    std::cout << std::endl;
    return 0;
}