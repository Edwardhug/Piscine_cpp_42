#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include <iostream>
#include <exception>

int main()
{
	Bureaucrat Martin;
	Bureaucrat* Sophie;

	std::cout << "Bureaucrat creation" << std::endl;
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

	std::cout << "\nChange grade" << std::endl;
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

	std::cout << "\nCreate form" << std::endl;
	ShrubberyCreationForm	Shrubbery("Home");
	RobotomyRequestForm		Robot("Poor subject");
	PresidentialPardonForm	Presidential("Lucky subject");
	

	// try to execute without sign

	std::cout << "\nExecute without sign" << std::endl;
	Sophie->executeForm(Shrubbery); //failure
	Sophie->executeForm(Robot);	//failure
	Sophie->executeForm(Presidential);	//failure

	//	sign form

	std::cout << "\nSign form" << std::endl;
	Martin.signForm(Shrubbery);	// failure
	Sophie->signForm(Shrubbery);	//success
	Martin.signForm(Robot);	// failure
	Sophie->signForm(Robot);	//success
	Martin.signForm(Presidential);	// failure
	Sophie->signForm(Presidential);	//success

	// execute form

	std::cout << "\nExecute form" << std::endl;
	Martin.executeForm(Shrubbery); //failure
	Sophie->executeForm(Shrubbery);	//success
	Martin.executeForm(Robot); //failure
	Sophie->executeForm(Robot);	//success
	Martin.executeForm(Presidential); //failure
	Sophie->executeForm(Presidential);	//success

	delete Sophie;
}