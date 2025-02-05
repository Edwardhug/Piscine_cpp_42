#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"
#include <exception>

bool isDigit(char *str) {
	int i = 0;
	while (str[i] == '+') {
		if ((str[i] == '+' && ((str[i+1] > '9' || str[i+1] < '0') && str[i + 1] != '+'))) {
			return (false);
		}
		i++;
	}
	int a = i;
	for (int i = a; str[i]; i++) {
		if ((str[i] > '9' || str[i] < '0'))
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
			std::cout << "Error: Need only positive numbers." << std::endl;
			return 1;
		}
	}

	PmergeMe Pmerge;
	try {
		Pmerge.fillVector(av);
	}
	catch (std::exception &e) {
		std::cout << "Error : too big number" << std::endl;
		return 1 ;
	}
	std::cout << "Before : ";
	Pmerge.printResult(Pmerge.getPairVec());
	Pmerge.setDeep(0);
	Pmerge.sortVec();
	std::cout << "After  : ";
	Pmerge.printResult(Pmerge.getResult());
	Pmerge.printTimeVec();

	try {
		Pmerge.fillDeque(av);
	}
	catch (std::exception &e) {
		std::cout << "Error : too big number" << std::endl;
		return 1 ;
	}
	Pmerge.setDeep(0);
	Pmerge.sortDeq();
	Pmerge.printTimeDeq();
}