#include <iostream>
#include "whatever.hpp"

// #include <vector>

int main( void )
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    const int ca = 5, cb = 6;
    std::cout << "min: " << min(ca, cb) << std::endl;
    std::cout << "max: " << max(ca, cb) << std::endl;

    // std::vector<int> v1, v2;
    // v1.push_back(1);
    // v1.push_back(2);
    // v2.push_back(1);
    // v2.push_back(3);

    // ::swap(v1, v2);
    // std::cout << ::min( v1, v2 ).at(1) << std::endl;
    // std::cout << ::max( v1, v2 ).at(1) << std::endl;

    // float f = 42.42;
    // double g = 21.21;

    // ::swap(f, g);

    return 0;
}