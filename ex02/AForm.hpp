#pragma once

#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _is_signed;
    const short _grade_to_sign;
    const short _grade_to_exec;
    AForm &operator=(const AForm &ref);

protected:
    AForm();

public:
    AForm(const std::string &name, const short grade_to_sign, const short grade_to_exec);
    AForm(const AForm &ref);
    virtual ~AForm();

    const std::string &getName() const;
    bool getIsSigned() const;
    short getGradeToSign() const;
    short getGradeToExec() const;

    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &os, const AForm &a);
