#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"

PmergeMe::PmergeMe() :_deep(0) {}

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
	// std::deque<unsigned int>::iterator	deqBegin = _deq.begin();
	// std::deque<unsigned int>::iterator	deqNext = deqBegin++;

	for (size_t i = 0; vecBegin != _vec.end() && vecNext != _vec.end(); i += 2) {
		if (*vecBegin > *vecNext) {
			_pairVec.push_back(new std::pair<unsigned int, unsigned int>(*vecBegin, *vecNext));
		} else {
			_pairVec.push_back(new std::pair<unsigned int, unsigned int>(*vecNext, *vecBegin));
		}
		vecBegin += 2;
		vecNext +=2;
	}
	// for (size_t i = 0; deqBegin != _deq.end() && deqNext != _deq.end(); i += 2) {
	// 	if (*deqBegin > *deqNext)
	// 		_pairDeq.push_back(std::make_pair(static_cast<void *>(&(*(deqBegin))), static_cast<void *>(&(*(deqNext)))));
	// 	else
	// 		_pairDeq.push_back(std::make_pair(static_cast<void *>(&(*(deqNext))), static_cast<void *>(&(*(deqBegin)))));
	// 	deqBegin += 2;
	// 	deqNext +=2;
	// }
}

unsigned int PmergeMe::data_of_pair(void *pairi) const {
	int i = 0;
	std::pair<void *, void *> *pair = static_cast<std::pair<void *, void *> *>(pairi);
	while (i != (_deep )) {
		pair = static_cast<std::pair<void *, void *> *>(pair->first);
		i++;
	}
	std::pair<unsigned int , unsigned int> *ballec = reinterpret_cast<std::pair<unsigned int, unsigned int> * >(pair);
	// std::cout << "pair->first = " << ballec->first << std::endl;
	return ballec-> first;
}
