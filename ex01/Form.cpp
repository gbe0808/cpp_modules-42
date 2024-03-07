#include <iostream>
#include "Form.hpp"

Form::Form(const string& name, const short grade_to_sign, const short grade_to_exec) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_exec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& ref) : _name(ref._name), _is_signed(ref._is_signed), _grade_to_sign(ref._grade_to_sign), _grade_to_exec(ref._grade_to_exec) {}

Form::~Form() {}

Form& Form::operator=(const Form& ref)
{
    (void)ref;
    return *this;
}

const string& Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _is_signed;
}

short Form::getGradeToSign() const
{
    return _grade_to_sign;
}

short Form::getGradeToExec() const
{
    return _grade_to_exec;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _grade_to_sign)
        throw GradeTooLowException();
    if (_is_signed)
        throw AlreadySignedException();
    _is_signed = true;
}

const char* Form::AlreadySignedException::what() const throw()
{
    return "Form is already signed\n";
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade is too high\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade is too low\n";
}

std::ostream& operator<<(std::ostream& os, const Form& a)
{
    os << a.getName() << "is" << (a.getIsSigned() ? " signed" : "n't signed") << '\n';
    os << "grade_to_sign: " << a.getGradeToSign() << ", grade_to_exec: " << a.getGradeToExec() << '\n';
    return os;
}
