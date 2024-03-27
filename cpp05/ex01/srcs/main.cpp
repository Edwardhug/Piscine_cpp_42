#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>
#include <exception>

int main()
{
	Bureaucrat Martin;
	Bureaucrat* Sophie;
	try {	//creation
		Sophie = new Bureaucrat("Sophie the boss", 1);
	}
	catch (std::exception &e) {
		std::cout << "Sophie " << e.what() << std::endl;
	}

	try {
		Bureaucrat Bengi("Bengi the impostor", 0);
	}
	catch (std::exception &e) {
		std::cout << "Bengi " << e.what() << std::endl;
	}

	try {	//change grade
		Sophie->increaseGrade();
	}
	catch (std::exception &e) {
		std::cout << "Sophie " << e.what() << std::endl;
	}
	try {
		Sophie->decreaseGrade();
	}
	catch (std::exception &e) {
		std::cout << "Sophie " << e.what() << std::endl;
	}
	std::cout << *Sophie;
	try {
		Sophie->increaseGrade();
	}
	catch (std::exception &e) {
		std::cout << "Sophie " << e.what() << std::endl;
	}
	std::cout << *Sophie;

	// create forms

	Form	Easy_form;
	Form	*Hard_form;
	try {	//error
		Hard_form = new Form("hard form", 160, 1);
	}
	catch (std::exception &e) {
		std::cout << "hard form " << e.what() << std::endl;
	}
	try {	//good
		Hard_form = new Form("hard form", 160, 1);
	}
	catch (std::exception &e) {
		std::cout << "hard form " << e.what() << std::endl;
	}

	//	sign form

	Martin.signForm(Easy_form);	//success
	Martin.signForm(*Hard_form);	//failure
	Sophie->signForm(*Hard_form);	//success

	delete Hard_form;
	delete Sophie;
}