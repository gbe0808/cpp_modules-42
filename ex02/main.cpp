#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

// void f() {system("leaks array");}

int main(int, char**)
{
    // atexit(f);
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    std::cout << "numbers\n";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << numbers[i] << ' ';
    std::cout << std::endl;
    
    //SCOPE
    {
        std::cout << "--------------------복사 테스트--------------------\n";
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        for (unsigned int i = 0; i < tmp.size(); i++)
            std::cout << "numbers[" << i << "] = " << tmp[i] << std::endl;
        
        for (unsigned int i = 0; i < test.size(); i++)
            std::cout << "numbers[" << i << "] = " << test[i] << std::endl;
    }

    std::cout << "--------------------중복값 테스트--------------------\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        std::cout << "-------------------인덱스 테스트 1-------------------\n";
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "-------------------인덱스 테스트 2-------------------\n";
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "-------------------인덱스 테스트 3-------------------\n";
        std::cout << "before number: " << numbers[MAX_VAL / 2] << std::endl;
        numbers[MAX_VAL / 2] = 0;
        std::cout << "after number: " << numbers[MAX_VAL / 2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "--------------------const 테스트--------------------\n";
    {
        const Array<int> tmp = numbers;
        for (unsigned int i = 0; i < MAX_VAL; i++)
            std::cout << "numbers[" << i << "] = " << tmp[i] << std::endl;
        // tmp[0] = 1;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    delete [] mirror;//
    return 0;
}