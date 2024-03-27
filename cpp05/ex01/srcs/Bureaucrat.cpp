#include "../includes/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Martin Dupond"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name) {
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
		this->_grade--;
}

void	Bureaucrat::decreaseGrade() {
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("grade too high");
}

const char*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("grade too low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &bureaucrat){
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (o);
}



