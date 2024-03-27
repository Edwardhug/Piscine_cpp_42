#include "../includes/Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	Bureaucrat Martin;
	try {
		Bureaucrat Sophie("Sophie the boss", 1);
	}
	catch (std::exception &e) {
		std::cout << "Exception catch" << std::endl;
	}

	try {
		Bureaucrat Bengi("Bengi the impostor", 0);
	}
	catch (std::exception &e) {
		std::cout << "Exception catch" << std::endl;
	}
}