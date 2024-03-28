#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
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

	ShrubberyCreationForm	Shrubbery("home");

	//	sign form

	Martin.signForm(Shrubbery);	// failure
	Sophie->signForm(Shrubbery);	//success

	// execute form

	Martin.executeForm(Shrubbery); //failure
	Sophie->executeForm(Shrubbery);	//success

	delete Sophie;
}