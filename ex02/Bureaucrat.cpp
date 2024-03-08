#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const string name, short grade) : _name(name), _grade(grade)
{
    cout << grade << '\n';
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref.getName()), _grade(ref.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
    (void)ref;
    return *this;
}

const string& Bureaucrat::getName() const
{
    return _name;
}

short Bureaucrat::getGrade() const
{
    return _grade;
}

// Since grade 1 is the highest one and 150 the lowest,
// incrementing a grade 3 should give a grade 2 to the bureaucrat.
void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low\n";
}

void Bureaucrat::executeForm(AForm const & form)
{
    try {
        form.execute(*this);
        cout << "Bureaucrat " << _name << " executes " << form.getName() << '\n';
    } catch(std::exception &e) {
        cerr << e.what();
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a)
{
    os << a.getName() << ", bureaucrat grade " << a.getGrade() << ".\n";
    return os;
}
