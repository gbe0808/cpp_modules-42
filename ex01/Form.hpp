#pragma once

#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _is_signed;
    const short _grade_to_sign;
    const short _grade_to_exec;
    Form();
    Form &operator=(const Form &ref);

public:
    Form(const std::string &name, const short grade_to_sign, const short grade_to_exec);
    Form(const Form &ref);
    ~Form();

    const std::string &getName() const;
    bool getIsSigned() const;
    short getGradeToSign() const;
    short getGradeToExec() const;

    void beSigned(Bureaucrat &bureaucrat);

    class AlreadySignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &a);
