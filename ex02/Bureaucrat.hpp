#pragma once

#include <exception>
#include <string>
#include "AForm.hpp"
using namespace std;

class AForm;

class Bureaucrat
{
private:
    const string _name;
    short _grade;
    Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &ref);

public:
    Bureaucrat(const string name, short grade);
    Bureaucrat(const Bureaucrat &ref);
    ~Bureaucrat();

    const string &getName() const;
    short getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm *form);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &a);