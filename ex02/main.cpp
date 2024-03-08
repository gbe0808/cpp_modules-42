#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    cout << "using namespace std를 지우시오.\n";

    // AForm form;

    try {
        AForm *f1 = new PresidentialPardonForm("form1");
        AForm *f2 = new RobotomyRequestForm("form2");
        AForm *f3 = new ShrubberyCreationForm("form3");

        Bureaucrat arr[4] = {
            Bureaucrat("jnho", 148),
            Bureaucrat("jbok", 90),
            Bureaucrat("jdoh", 40),
            Bureaucrat("jpark2", 2)
        };
        
        for (int i = 0; i < 4; i++) {
            arr[i].executeForm(*f1);
            arr[i].executeForm(*f2);
            arr[i].executeForm(*f3);
        }

    } catch (std::exception &e) {
        cerr << e.what() << '\n';
    }

    return 0;
}