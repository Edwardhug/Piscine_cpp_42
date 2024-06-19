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

void	PmergeMe::printPair() {
	std::vector<std::pair<void *, void*> >::iterator vecBegin = _pairVec.begin();
	std::cout << "vec pair = ";
	while (vecBegin != _pairVec.end()) {
		std::cout << *static_cast<unsigned int*>(vecBegin->first) << " ";
		vecBegin++;
	}
	vecBegin = _pairVec.begin();
	std::cout << "\n           ";
	while (vecBegin != _pairVec.end()) {
		std::cout << *static_cast<unsigned int*>(vecBegin->second) << " ";
		vecBegin++;
	}
	std::cout << std::endl;

	std::deque<std::pair<void *, void*> >::iterator deqBegin = _pairDeq.begin();
	std::cout << "deq pair = ";
	while (deqBegin != _pairDeq.end()) {
		std::cout << *static_cast<unsigned int*>(deqBegin->first) << " ";
		deqBegin++;
	}
	deqBegin = _pairDeq.begin();
	std::cout << "\n           ";
	while (deqBegin != _pairDeq.end()) {
		std::cout << *static_cast<unsigned int*>(deqBegin->second) << " ";
		deqBegin++;
	}
	std::cout << std::endl;
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

void	PmergeMe::fillPair() {
	std::vector<unsigned int>::iterator	vecBegin = _vec.begin();
	std::vector<unsigned int>::iterator	vecNext = vecBegin++;
	std::deque<unsigned int>::iterator	deqBegin = _deq.begin();
	std::deque<unsigned int>::iterator	deqNext = deqBegin++;

	for (size_t i = 0; vecBegin != _vec.end() && vecNext != _vec.end(); i += 2) {
		if (*vecBegin > *vecNext)
			_pairVec.push_back(std::make_pair(static_cast<void *>(&(*(vecBegin))), static_cast<void *>(&(*(vecNext)))));
		else
			_pairVec.push_back(std::make_pair(static_cast<void *>(&(*(vecNext))), static_cast<void *>(&(*(vecBegin)))));
		vecBegin += 2;
		vecNext +=2;
	}
	// TODO besoin de demander a brieux ce que je dois faire du dernier chiffre si jamais c'est impair
	for (size_t i = 0; deqBegin != _deq.end() && deqNext != _deq.end(); i += 2) {
		if (*deqBegin > *deqNext)
			_pairDeq.push_back(std::make_pair(static_cast<void *>(&(*(deqBegin))), static_cast<void *>(&(*(deqNext)))));
		else
			_pairDeq.push_back(std::make_pair(static_cast<void *>(&(*(deqNext))), static_cast<void *>(&(*(deqBegin)))));
		deqBegin += 2;
		deqNext +=2;
	}
	// TODO ici aussi
}

// void	PmergeMe::sortVec() {
// }