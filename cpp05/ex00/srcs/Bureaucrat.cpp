#include "../includes/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Martin Dupond"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	this->_grade = copy._grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy) {
	this->_grade = copy._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::increaseGrade() {
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade++;
}

void	Bureaucrat::decreaseGrade() {
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade--;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	std::cout << "Grade too high sorry" << std::endl;
}

const char*Bureaucrat::GradeTooLowException::what() const throw() {
	std::cout << "Grade too low sorry" << std::endl;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &bureaucrat){
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
}

