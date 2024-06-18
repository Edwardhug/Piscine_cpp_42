#include "../includes/PmergeMe.hpp"

#include <iostream>

bool isDigit(char *str) {
	for (int i = 0; str[i]; i++) {
		if (str[i] > '9' || str[i] < '0')
			return (false);
	}
	return (true);
}

int main(int ac, char **av) {
	if (ac < 3) {
		std::cout << "Error: No Pmerge to do." << std::endl;
		return 1;
	}
	for (int i = 1; av[i]; i++) {
		if (isDigit(av[i]) == false) {
			std::cout << "Error: Need online positive numbers." << std::endl;
			return 1;
		}
	}
}