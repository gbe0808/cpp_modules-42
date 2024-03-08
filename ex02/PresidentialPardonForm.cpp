#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, SIGN_GRADE, EXEC_GRADE) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm(ref.getName(), SIGN_GRADE, EXEC_GRADE) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	(void) ref;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();
    if (getIsSigned())
        throw AlreadySignedException();
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox\n";
}
