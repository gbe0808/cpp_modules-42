#include <fstream>
#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, SIGN_GRADE, EXEC_GRADE) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref.getName(), SIGN_GRADE, EXEC_GRADE) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	(void) ref;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();
    if (getIsSigned())
        throw AlreadySignedException();

	std::ofstream outfile(getName() + "_shrubbery", std::ios::out | std::ios::trunc);

	if (!outfile)
		throw "File cannot be opened\n";

	outfile << "     ###\n";
	outfile << "    #o###\n";
	outfile << "  #####o###\n";
	outfile << " #o#\\#|#/###\n";
	outfile << "  ###\\|/#o#\n";
	outfile << "   # }|{  #\n";
	outfile << "     }|{\n";

	outfile.close();
}
