#include <iostream>
#include "Bureaucrat.hpp"
using namespace std;

int main()
{
    cout << "using namespace std를 지우시오.\n";

    try {
        Bureaucrat jnho("jnho", 0);
        cout << jnho;
    } catch (std::exception& e) {
        cerr << e.what() << '\n';
    }

    cout << "--------------------------------------------\n";

    try {
        Bureaucrat jbok("jbok", 50);
        cout << jbok;

        jbok.incrementGrade();
        cout << jbok;

        jbok.decrementGrade();
        cout << jbok;
    } catch (std::exception& e) {
        cerr << e.what() << '\n';
    }

    cout << "--------------------------------------------\n";

    try {
        Bureaucrat jdoh("jdoh", 151);
        cout << jdoh;
    } catch (std::exception& e) {
        cerr << e.what() << '\n';
    } catch (Bureaucrat::GradeTooLowException& e) {
        cerr << e.what() << '\n';
    }

    cout << "--------------------------------------------\n";

    try {
        Bureaucrat jpark2("jpark2", 150);
        cout << jpark2;

        jpark2.incrementGrade();
        cout << jpark2;

        jpark2.decrementGrade();
        cout << jpark2;

        jpark2.decrementGrade();
        cout << jpark2;

        jpark2.incrementGrade();
        cout << jpark2;
    } catch (std::exception& e) {
        cerr << e.what() << '\n';
    }
    cout << "--------------------------------------------\n";

    return 0;
}