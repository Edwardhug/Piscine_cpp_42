# include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("For anyone") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), _target(copy._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy) {
	this->_target = copy._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)const {
	if (executor.getGrade() > this->getToExec())
		throw GradeTooLowException();
	else if (this->getSigned() == false)
		throw GradeTooHighException();
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}
