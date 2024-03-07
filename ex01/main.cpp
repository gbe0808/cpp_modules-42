#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    cout << "using namespace std를 지우시오.\n";

    try {
        Form f1("form1", 0, 0);
        Form f2("form2", 0, 50);
        Form f3("form3", 0, 151);
        Form f4("form4", 50, 0);
        Form f5("form5", 50, 50);
        Form f6("form6", 50, 151);
        Form f7("form7", 151, 0);
        Form f8("form8", 151, 50);
        Form f9("form9", 151, 151);
    } catch (std::exception &e) {
        cerr << e.what() << '\n';
    }

    cout << "--------------------------------------------\n\n";

    try {
        Form cleanser1("Perfect Whip", 10, 10);
        Form cleanser2("Dr. G", 10, 10);
        Bureaucrat jnho("jnho", 9);
        Bureaucrat jbok("jbok", 10);
        Bureaucrat jdoh("jdoh", 11);

        jnho.signForm(cleanser1);
        jbok.signForm(cleanser1);
        jdoh.signForm(cleanser1);

        jdoh.signForm(cleanser2);
        jbok.signForm(cleanser2);
        jnho.signForm(cleanser2);

    } catch (std::exception &e) {
        cerr << e.what() << '\n';
    }

    return 0;
}
