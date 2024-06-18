#include "../includes/PmergeMe.hpp"


unsigned int atoui(char *str) {
	unsigned long int ret = 0;
	int i = 0;
	int	j = 1;

	while (str[i] && str[i + 1]) 
		i++;
	while (i >= 0) {
		ret += (str[i] - '0') * j;
		j *= 10;
		i--;
	}
	if (ret > 4294967295)
		throw (std::exception());
	return (ret);
}

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &copy) {
	_vec = copy._vec;
	_deq = copy._deq;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy) {
	_vec = copy._vec;
	_deq = copy._deq;
	return (*this);
}

void	PmergeMe::fillContainers(char **av) {
	for (size_t i = 1; av[i]; i++)
		_vec.push_back(atoui(av[i]));
	for (size_t i = 1; av[i]; i++)
		_deq.push_back(atoui(av[i]));
}

void	PmergeMe::printVec() {
	std::cout << "Vec = ";
	for (std::vector<unsigned int>::iterator begin = _vec.begin(); begin != _vec.end(); begin++) {
		std::cout << *begin << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeq() {
	std::cout << "Deq = ";
	for (std::deque<unsigned int>::iterator begin = _deq.begin(); begin != _deq.end(); begin++) {
		std::cout << *begin << " ";
	}
	std::cout << std::endl;
}