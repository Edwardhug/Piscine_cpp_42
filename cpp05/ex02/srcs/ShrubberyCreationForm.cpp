# include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("For anyone") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {
	this->_target = copy._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const {
	std::string filename;

	filename = _target + "_shrubbery";
	if (executor.getGrade() > this->getToExec())
		throw GradeTooLowException();
	else
	{
		std::ofstream file(filename.c_str());
		if (file.is_open())
		{
			file << "      /\\      " << std::endl;
			file << "     /\\*\\     " << std::endl;
			file << "    /\\O\\*\\    " << std::endl;
			file << "   /\\/*/\\*\\   " << std::endl;
			file << "  /\\O\\/\\*\\/\\  " << std::endl;
			file << " /\\*\\/\\*\\/\\*\\ " << std::endl;
			file << "/\\O\\/\\*\\/*/\\/\\" << std::endl;
			file << "      ||      " << std::endl;
			file << "      ||      " << std::endl;
			file << "      ||      " << std::endl;
			file.close();
		}
		else
			std::cout << "Error during file opening" << std::endl;
	}
}
