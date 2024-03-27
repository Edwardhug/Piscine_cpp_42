#include "../includes/Form.hpp"

Form::Form() : _name("Simple form"),  _signed(false), _toSign(150), _toExec(150) {}

Form::Form(std::string name, int toSign, int toExec) : _name(name), _signed(false),_toSign(toSign), _toExec(toExec) {
	if (toSign > 150 || toExec > 150)
		throw GradeTooLowException();
	else if (toSign < 1 || toExec < 1)
		throw GradeTooHighException();
}

Form::~Form() {}

Form::Form(Form const &copy) : _name(copy._name), _signed(copy._signed), _toSign(copy._toSign), _toExec(copy._toExec) {}

Form &Form::operator=(Form const &copy) {
	this->_signed = copy._signed;
	return (*this);
}

std::string	Form::getName() const {
	return _name;
}

bool	Form::getSigned() const {
	return _signed;
}

int	Form::getToSign() const {
	return _toSign;
}

int Form::getToExec() const {
	return _toExec;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("grade too low");
}

std::ostream &operator<<(std::ostream &o, Form &form) {
	std::cout << form.getName() << ", to sign " << form.getToSign() << ", to execute " << form.getToExec() << ", and is it signed :" << form.getSigned() << std::endl;
	return o;
}

void	Form::beSigned(Bureaucrat const bureaucrat){
	if (bureaucrat.getGrade() > this->_toSign)
		throw GradeTooLowException();
	else
		_signed = true;
}
