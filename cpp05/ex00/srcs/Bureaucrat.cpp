#include "../includes/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Martin Dupond"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) {
	try
	{
		grade < 1 == true;
	}
	catch (std::exception & e)
	{
		std::cout << "Grade too low in the constructor" << std::endl;
		return ;
	}
	try
	{
		grade > 150 == true;
	}
	catch (std::exception & e)
	{
		std::cout << "Grade too high in the constructor" << std::endl;
		return ;
	}
	// _name = name;	don't work because the name is a const
	this->_grade = grade;

}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy) {
	// this->_name = copy._name;		dont work because the name is a const
	this->_grade = copy._grade;
	return (*this);
}

