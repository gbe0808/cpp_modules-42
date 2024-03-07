#include <fstream>
#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const string &target) : AForm(target, SIGN_GRADE, EXEC_GRADE) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref.getName(), SIGN_GRADE, EXEC_GRADE) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	(void) ref;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) {
	std::ofstream outfile(getName() + "_shrubbery", std::ios::out | std::ios::trunc);

	if (!outfile)
		throw "File cannot be opened\n";

	outfile << "     ###";
	outfile << "    #o###";
	outfile << "  #####o###";
	outfile << " #o#\\#|#/###";
	outfile << "  ###\\|/#o#";
	outfile << "   # }|{  #";
	outfile << "     }|{";

	outfile.close();
}
