#pragma once

#include <exception>
#include <string>

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
