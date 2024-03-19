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

void print_const_int(const int &i)
{
    std::cout << i << ' ';
}

int main()
{
    int arr_int[5] = {1, 3, 5, 7, 9};
    char arr_char[5] = {'a', 'b', 'c', 'd', 'e'};
    const int arr_const[5] = {2, 4, 6, 8, 10};

    ::iter(arr_int, 5, print_int);
    std::cout << std::endl;
    ::iter(arr_int, 5, multi_int);
    ::iter(arr_int, 5, print_int);
    std::cout << std::endl;
    ::iter(arr_char, 5, print_char);
    std::cout << std::endl;
    ::iter(arr_const, 5, print_const_int);
    return 0;
}