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

// void	PmergeMe::printPair() {
// 	std::vector<std::pair<void *, void*> >::iterator vecBegin = _pairVec.begin();
// 	std::cout << "vec pair = ";
// 	while (vecBegin != _pairVec.end()) {
// 		std::cout << *static_cast<unsigned int*>(vecBegin->first) << " ";
// 		vecBegin++;
// 	}
// 	vecBegin = _pairVec.begin();
// 	std::cout << "\n           ";
// 	while (vecBegin != _pairVec.end()) {
// 		std::cout << *static_cast<unsigned int*>(vecBegin->second) << " ";
// 		vecBegin++;
// 	}
// 	std::cout << std::endl;

// 	std::deque<std::pair<void *, void*> >::iterator deqBegin = _pairDeq.begin();
// 	std::cout << "deq pair = ";
// 	while (deqBegin != _pairDeq.end()) {
// 		std::cout << *static_cast<unsigned int*>(deqBegin->first) << " ";
// 		deqBegin++;
// 	}
// 	deqBegin = _pairDeq.begin();
// 	std::cout << "\n           ";
// 	while (deqBegin != _pairDeq.end()) {
// 		std::cout << *static_cast<unsigned int*>(deqBegin->second) << " ";
// 		deqBegin++;
// 	}
// 	std::cout << std::endl;
// }

PmergeMe::PmergeMe() :_deep(0) {

}

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
	while (i != _deep) {
		std::cout << "here " << i << std::endl;
		pair = static_cast<std::pair<void *, void *> *>(pair->first);
		i++;
	}
	std::pair<unsigned int , unsigned int> *ballec = reinterpret_cast<std::pair<unsigned int, unsigned int> * >(pair);
	return ballec-> first;
}

void swap(std::vector<std::pair<void *, void *> *>::iterator it) {
	void * tmp = (*it)->first;
	(*it)->first = (*it)->second;
	(*it)->second = tmp;
}

void PmergeMe::compare_and_swap(std::vector<std::pair<void *, void *> *>::iterator it) {
	std::pair<void *, void *> *pair = *it;
	unsigned int	first = data_of_pair(&(pair->first));
	unsigned int	second = data_of_pair(&(pair->second));
	if (first < second) {
		swap(it);
	}
	std::cout<< "first = " << first << std::endl;
	std::cout<< "second = " << second << std::endl;
	std::cout << "I SWAP BITCHES" << std::endl;
}

std::vector<std::pair<void *, void *> *>	PmergeMe::pairageVec(std::vector<std::pair<void *, void *> *> &toSort) {

	std::cout << "pairage" << std::endl;

	std::vector<std::pair<void *, void *> *> newVec;
	for (std::vector<std::pair<void *, void *> *>:: iterator it = toSort.begin() ; it != toSort.end() ; it++) {
		void * first = *it;
		it++;
		if (it == toSort.end())
			break ;
		void * second = *it;
		std::pair<void *, void *> *pair = new std::pair<void*, void*>(first, second);
		std::cout << "pairage value : "  << std::endl;
		newVec.push_back(pair);
	}
	for (std::vector<std::pair<void *, void *> *>::iterator it = newVec.begin() ; it != newVec.end() ; it++) {
		compare_and_swap(it);
	}
	return (newVec);
}

std::pair<void *, void *> *last(std::vector<std::pair<void *, void *> *> &toSort) {
	if (toSort.size() % 2){
		return (*(--toSort.end()));
	}
	return NULL;
}

std::vector<std::pair<void *, void *>*>	PmergeMe::recursivSortVec(std::vector<std::pair<void *, void *> *> &toSort) {
	_deep++;
	std::cout << "we need to go deeper : " << _deep << std::endl;
	std::vector<std::pair<void *, void *> *> newVec = pairageVec(toSort);
	std::pair<void *, void *> *dernier_elem = last(toSort); // renvoi un last si la len est impaire sinon renvoi null
	if (newVec.size() == 1)
		return newVec;
	_deep--;
	if (dernier_elem)
		std::cout << "dernier element" << data_of_pair(static_cast<std::pair<void *, void*>*>(dernier_elem)) << std::endl;
	_deep++;
	std::vector<std::pair<void *, void *>*> return_vec = recursivSortVec(newVec);
	(void)dernier_elem;
	if (dernier_elem) {
		std::cout << " y a un ptn de dernier element";
	} else {
		std:: cout << "NON";
	}
	std :: cout << std::endl;

	//depairage
	// insertion du dernier element
	// if (dernier_elem) {
	// 	insertion_binaire(newVec, dernier_elem);
	// }
	return return_vec;
}

std::vector<std::pair<void *, void *>* > serializer(std::vector<std::pair<unsigned int, unsigned int>*> toi) {
	std::vector<std::pair< void * , void *> * > return_val;
	for (std::vector< std::pair< unsigned int, unsigned int > *>::iterator it = toi.begin() ; it != toi.end() ; it++) {
		return_val.push_back(reinterpret_cast<std::pair<void *, void *> *>(*it));
	}
	return return_val;
}

void	PmergeMe::sortVecFirst() {
	std::vector<std::pair<void *, void *> *>	toSort;
	std::cout << "sort" << std::endl;
	toSort = serializer(_pairVec);
	recursivSortVec(toSort);

}