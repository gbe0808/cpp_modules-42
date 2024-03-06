#pragma once

#include <exception>
#include <string>
#include "Bureaucrat.hpp"
using namespace std;

class Bureaucrat;

class Form
{
private:
    const string _name;
    bool _is_signed;
    const short _grade_to_sign;
    const short _grade_to_exec;
    Form();
    Form &operator=(const Form &ref);

public:
    Form(const string &name, const short grade_to_sign, const short grade_to_exec);
    Form(const Form &ref);
    ~Form();

    const string &getName() const;
    bool getIsSigned() const;
    short getGradeToSign() const;
    short getGradeToExec() const;

    void beSigned(Bureaucrat &bureaucrat);

    class AlreadySignedException : public exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooHighException : public exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &a);