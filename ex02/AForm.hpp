#pragma once

#include <exception>
#include <string>
#include "Bureaucrat.hpp"
using namespace std;

class Bureaucrat;

class AForm
{
private:
    const string _name;
    bool _is_signed;
    const short _grade_to_sign;
    const short _grade_to_exec;
    AForm();
    AForm &operator=(const AForm &ref);

public:
    AForm(const string &name, const short grade_to_sign, const short grade_to_exec);
    AForm(const AForm &ref);
    virtual ~AForm();

    const string &getName() const;
    bool getIsSigned() const;
    short getGradeToSign() const;
    short getGradeToExec() const;

    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &os, const AForm &a);