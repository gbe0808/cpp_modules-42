#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat jnho("jnho", 0);
        std::cout << jnho;
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "--------------------------------------------\n";

    try {
        Bureaucrat jbok("jbok", 50);
        std::cout << jbok;

        jbok.incrementGrade();
        std::cout << jbok;

        jbok.decrementGrade();
        std::cout << jbok;
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "--------------------------------------------\n";

    try {
        Bureaucrat jdoh("jdoh", 151);
        std::cout << jdoh;
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "--------------------------------------------\n";

    try {
        Bureaucrat jpark2("jpark2", 150);
        std::cout << jpark2;

        jpark2.incrementGrade();
        std::cout << jpark2;

        jpark2.decrementGrade();
        std::cout << jpark2;

        jpark2.decrementGrade();
        std::cout << jpark2;

        jpark2.incrementGrade();
        std::cout << jpark2;
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------------------------\n";

    return 0;
}
