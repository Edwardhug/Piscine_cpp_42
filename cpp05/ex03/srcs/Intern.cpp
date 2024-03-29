#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &copy) {(void)copy;}

Intern &Intern::operator=(Intern const &copy) {
	(void)copy;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	std::string	forms[3];
	int i = 0;

	forms[0] = "presidential pardon";
	forms[1] = "robotomy request";
	forms[2] = "shrubbery creation";

	while (i < 3)
	{
		if (name == forms[i])
			break ;
		i++;
	}

	AForm *form;
	form = NULL;
	switch(i)
	{
		case (0) :
			std::cout << "Intern creates " << name << std::endl;
			form = new PresidentialPardonForm(target);
			break ;

		case (1) :
			std::cout << "Intern creates " << name << std::endl;
			form = new RobotomyRequestForm(target);
			break ;
		case (2) :
			std::cout << "Intern creates " << name << std::endl;
			form = new ShrubberyCreationForm(target);
			break ;
		default :
			std::cout << "Intern can't create a form like this, do you want a coffee ?" << std::endl;
			break ;
	}
	return (form);
}