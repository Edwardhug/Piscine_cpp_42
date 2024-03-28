# include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("For anyone") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _target(copy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {
	this->_target = copy._target;
	return (*this);
}


void	RobotomyRequestForm::execute(Bureaucrat const &executor)const {
	if (executor.getGrade() > this->getToExec())
		throw GradeTooLowException();
	else if (this->getSigned() == false)
		throw GradeTooHighException();
	else
	{
		srand((unsigned int)time(0));
		std::cout << "**DRIIIIIIIIIILL**" << std::endl;
		if (rand() % 2 == 1)
			std::cout << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << _target << " robotomize failed" << std::endl;
	}
}
