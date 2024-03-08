#include <cstdlib>
#include <ctime>
#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm() {}

RobotomyRequestForm::RobotomyRequestForm(const string &target) : AForm(target, SIGN_GRADE, EXEC_GRADE) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm(ref.getName(), SIGN_GRADE, EXEC_GRADE) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	(void) ref;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();
    if (getIsSigned())
        throw AlreadySignedException();

	cout << "zeeeing~~\n";

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int rand_val = std::rand() & 1;

	if (rand_val)
		cout << executor.getName() << " has been robotomized successfully\n";
	else
		cout << executor.getName() << " has failed to be robotomized..\n";
}
