#include "../includes/Harl.hpp"
#include <iostream>

int main()
{
	Harl harl;

	std::std::cout << "DEBUG: " << std::std::endl;
	harl.complain("DEBUG");
	std::std::cout << "INFO: " << std::std::endl;
	harl.complain("INFO");
	std::std::cout << "WARNING: " << std::std::endl;
	harl.complain("WARNING");
	std::std::cout << "ERROR: " << std::std::endl;
	harl.complain("ERROR");
}