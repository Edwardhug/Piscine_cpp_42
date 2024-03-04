#include "../includes/Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	Harl harl;

	if (ac == 1) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	harl.complain(av[1]);
	(void)ac;
}