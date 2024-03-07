#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	static const short SIGN_GRADE = 25;
	static const short EXEC_GRADE = 5;

	PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

public:
	PresidentialPardonForm(const string &target);
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor);

};