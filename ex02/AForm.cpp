#include <iostream>
#include "AForm.hpp"

AForm::AForm() : _name(""), _is_signed(false), _grade_to_sign(0), _grade_to_exec(0) {}

AForm::AForm(const string& name, const short grade_to_sign, const short grade_to_exec) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_exec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& ref) : _name(ref._name), _is_signed(ref._is_signed), _grade_to_sign(ref._grade_to_sign), _grade_to_exec(ref._grade_to_exec) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& ref)
{
    (void)ref;
    return *this;
}

const string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _is_signed;
}

short AForm::getGradeToSign() const
{
    return _grade_to_sign;
}

short AForm::getGradeToExec() const
{
    return _grade_to_exec;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    const short grade = bureaucrat.getGrade();
    if (grade > _grade_to_sign)
        throw GradeTooLowException();
    if (_is_signed)
        throw AlreadySignedException();
    _is_signed = true;
}

const char* AForm::AlreadySignedException::what() const throw()
{
    return "Form is already signed\n";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form Grade is too high\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form Grade is too low\n";
}

std::ostream& operator<<(std::ostream& os, const AForm& a)
{
    os << a.getName() << "is" << (a.getIsSigned() ? " signed" : "n't signed") << '\n';
    os << "grade_to_sign: " << a.getGradeToSign() << ", grade_to_exec: " << a.getGradeToExec() << '\n';
    return os;
}
