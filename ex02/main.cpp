#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void leak_func()
{
    system("leaks ex02");
}

int main()
{
    // atexit(leak_func);

    // AForm form;

    AForm *f1 = NULL, *f2 = NULL, *f3 = NULL;

    try {
        f1 = new PresidentialPardonForm("form1");
        f2 = new RobotomyRequestForm("form2");
        f3 = new ShrubberyCreationForm("form3");

        Bureaucrat arr[4] = {
            Bureaucrat("jnho", 148),
            Bureaucrat("jbok", 90),
            Bureaucrat("jdoh", 40),
            Bureaucrat("jpark2", 2)
        };

        int test_bureaucrat = 3;
        if (test_bureaucrat < 1 || test_bureaucrat > 4)
            throw "out of bound";
        for (int i = 0; i < test_bureaucrat; i++) {
            arr[i].executeForm(*f1);
            arr[i].executeForm(*f2);
            arr[i].executeForm(*f3);
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    if (f1)
        delete f1;
    if (f2)
        delete f2;
    if (f3)
        delete f3;

    return 0;
}
