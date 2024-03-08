#pragma once

#include <exception>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    short _grade;
    Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &ref);

public:
    Bureaucrat(const std::string name, short grade);
    Bureaucrat(const Bureaucrat &ref);
    ~Bureaucrat();

    const std::string &getName() const;
    short getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &form);
    void executeForm(AForm const & form);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &a);
