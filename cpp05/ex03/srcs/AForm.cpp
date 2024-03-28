#include "../includes/AForm.hpp"

AForm::AForm() : _name("Simple form"),  _signed(false), _toSign(150), _toExec(150) {}

AForm::AForm(std::string name, int toSign, int toExec) : _name(name), _signed(false),_toSign(toSign), _toExec(toExec) {
	if (toSign > 150 || toExec > 150)
		throw GradeTooLowException();
	else if (toSign < 1 || toExec < 1)
		throw GradeTooHighException();
}

AForm::~AForm() {}

AForm::AForm(AForm const &copy) : _name(copy._name), _signed(copy._signed), _toSign(copy._toSign), _toExec(copy._toExec) {}

AForm &AForm::operator=(AForm const &copy) {
	this->_signed = copy._signed;
	return (*this);
}

std::string	AForm::getName() const {
	return _name;
}

bool	AForm::getSigned() const {
	return _signed;
}

int	AForm::getToSign() const {
	return _toSign;
}

int AForm::getToExec() const {
	return _toExec;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("form isn't signed");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("grade too low");
}

std::ostream &operator<<(std::ostream &o, AForm &form) {
	std::cout << form.getName() << ", to sign " << form.getToSign() << ", to execute " << form.getToExec() << ", and is it signed :" << form.getSigned() << std::endl;
	return o;
}

void	AForm::beSigned(Bureaucrat const bureaucrat){
	if (bureaucrat.getGrade() > this->_toSign)
		throw GradeTooLowException();
	else
		_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->_toExec)
		throw GradeTooLowException();
	else
		std::cout << "Form " << this->_name << " was executed" << std::endl;
}
