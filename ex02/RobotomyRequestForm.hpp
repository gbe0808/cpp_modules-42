#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	static const short SIGN_GRADE = 72;
	static const short EXEC_GRADE = 45;

	RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

public:
	RobotomyRequestForm(const string &target);
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;

};