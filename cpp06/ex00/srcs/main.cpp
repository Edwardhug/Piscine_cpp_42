#include "../includes/ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Wrong number of arg" << std::endl;
		return (1);
	}
	std::string	arg = av[1];
	ScalarConverter::convert(arg);
}