#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	static const short SIGN_GRADE = 145;
	static const short EXEC_GRADE = 137;

	ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

public:
	ShrubberyCreationForm(const string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;

};