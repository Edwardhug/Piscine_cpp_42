#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"
#include <algorithm>

std::vector<std::pair<void *, void *>*> PmergeMe::getPairVec() {
	return (_pairVec);
}

void PmergeMe::fillVector(char **av) {
    for (size_t i = 1; av[i]; i++) {
        _vec.push_back(atoui(av[i]));
    }
	for (std::vector<void *>::iterator it = _vec.begin(); it != _vec.end(); it ++) {
		_pairVec.push_back(new std::pair<void *, void *>(*it, NULL));
	}
}

unsigned long int	PmergeMe::dataOfPairVector(std::vector<std::pair<void *, void *> *>::iterator it) {
	int i = 0;
	std::pair<void *, void *> *pair = static_cast<std::pair<void *, void *> *>(*it);
	while (i != (_deep )) {
		pair = static_cast<std::pair<void *, void *> *>(pair->first);
		i++;
	}
	std::pair<unsigned int , unsigned int> *result = reinterpret_cast<std::pair<unsigned int, unsigned int> * >(pair);
	return result-> first;
}

void	PmergeMe::freeVecPair(std::vector<std::pair<void *, void *> *> vec) {
	for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); it++) {
		delete(*it);
	}
}

std::vector<std::pair<void *, void *> *>	PmergeMe::pairingVec(std::vector<std::pair<void *, void *> *> &toSort) {
	std::vector<std::pair<void *, void *> *> newVec;
	for (std::vector<std::pair<void *, void *> *>::iterator it = toSort.begin(); it != toSort.end() && (it + 1) != toSort.end(); it += 2) {
		if (dataOfPairVector(it) > dataOfPairVector(it + 1))
			newVec.push_back(new std::pair<void*, void*>(*it, *(it + 1)));
		else
			newVec.push_back(new std::pair<void*, void*>(*(it + 1), *it));
	}
	if (toSort.size() % 2 == 1) {
		for (std::vector<std::pair<void *, void *> *>::iterator it = toSort.begin(); it != toSort.end(); it ++) {
			if ((it + 1) == toSort.end())
				newVec.push_back(new std::pair<void *, void *>(*it, NULL));
		}
	}
	return newVec;
}

std::vector<std::pair<void *, void *>*> PmergeMe::getOnlyBigVec(std::vector<std::pair<void *, void *> *> &vec) {
    std::vector<std::pair<void *, void *>*> toRet;
    for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); it++) {
        toRet.push_back(static_cast<std::pair<void *, void *> *>((*it)->first));
    }
    return toRet;
}

std::vector<std::pair<void *, void *>*> PmergeMe::getOnlySmallVec(std::vector<std::pair<void *, void *> *> &vec) {
    std::vector<std::pair<void *, void *>*> toRet;
    for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); it++) {
		if ((*it)->second != NULL)
        	toRet.push_back(static_cast<std::pair<void *, void *> *>((*it)->second));
    }
    return toRet;
}

std::vector<std::pair<void *, void *>*> PmergeMe::depairingVec(std::vector<std::pair<void *, void *> *> &toDep) {
	std::vector<std::pair<void *, void *>*> bigNumber = getOnlyBigVec(toDep);
    std::vector<std::pair<void *, void *>*> smallNumber = getOnlySmallVec(toDep);

	std::vector<std::pair<void *, void *>*> afterDep = mergeInsertionVec(bigNumber, smallNumber);
	return (afterDep);
}

std::vector<std::pair<void *, void *> *>	PmergeMe::recursiveSortVec(std::vector<std::pair<void *, void *> *> before) {
	_deep++;

	if (before.size() <= 1) {
		_deep--;
		return (before);
	}
	std::vector<std::pair<void *, void *> *> newVec = pairingVec(before);
	std::vector<std::pair<void *, void *> *> retVec = recursiveSortVec(newVec);

	retVec = depairingVec(retVec);
	for (std::vector<std::pair<void *, void *> *>::iterator it = newVec.begin(); it != newVec.end(); ++it) {
        delete *it;
    }
	_deep--;
	return (retVec);
}

void	PmergeMe::sortVec() {
	std::vector<std::pair<void *, void *> *> toSort;
	setBeforeVec();
	_result = recursiveSortVec(_pairVec);
	setAfterVec();
}




// std::vector<std::pair<void *, void *>*> PmergeMe::mergeInsertionVec(std::vector<std::pair<void *, void *>*>& bigNumbers, std::vector<std::pair<void *, void *>*>& smallNumbers) {
//     std::vector<std::pair<void *, void *>*> result;
//     result.reserve(bigNumbers.size() + smallNumbers.size());
//     result = bigNumbers;
//     if (smallNumbers.empty()) {
//         return result;
//     }
//     std::vector<size_t> jacobsthal;
//     jacobsthal.push_back(1);
//     jacobsthal.push_back(3);
//     while (jacobsthal.back() < smallNumbers.size()) {
//         jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
//     }
//     for (size_t i = 0; i < smallNumbers.size(); ++i) {
// 		int j = 0;
//         std::pair<void *, void *>* toInsert = smallNumbers[i];
//         size_t left = 0;
//         size_t right = result.size();
//         while (left < right) {
//             size_t mid = left + (right - left) / 2;
//             if (dataOfPairVector(result.begin() + mid) < dataOfPairVector(smallNumbers.begin() + i)) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
// 			j++;
//         }
// 		std::cout << "nombre de comparaison pour cette insertion = " << j << std::endl;
//         result.insert(result.begin() + left, toInsert);
// 	}
//     return result;
// }

std::vector<std::pair<void *, void *>*> PmergeMe::mergeInsertionVec(std::vector<std::pair<void *, void *>*>& bigNumbers, std::vector<std::pair<void *, void *>*>& smallNumbers) {
    std::vector<std::pair<void *, void *>*> result;
    result.reserve(bigNumbers.size() + smallNumbers.size());
    result = bigNumbers;
    if (smallNumbers.empty()) {
        return result;
    }
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    while (jacobsthal.back() < smallNumbers.size()) {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    // Generate the Jacobsthal insertion order
	std::vector<size_t> insertionOrder;
	size_t lastJacob = 0;
	// size_t currentJacob = 1;
	for (size_t i = 0; i < jacobsthal.size(); ++i) {
	    size_t j = jacobsthal[i];
	    // Insert elements from j down to lastJacob + 1
	    for (size_t k = j; k > lastJacob; --k) {
	        if (k - 1 < smallNumbers.size()) {
	            insertionOrder.push_back(k - 1);
	        }
	    }
	    lastJacob = j;
	    if (j >= smallNumbers.size()) {
	        break;
	    }
	}
	for (std::vector<size_t>::iterator it = insertionOrder.begin(); it != insertionOrder.end(); it++) {
		std::cout << "insertion order " << *it << std::endl;
	}

	// Insert elements according to the generated order
	for (std::vector<size_t>::iterator it = insertionOrder.begin(); it != insertionOrder.end(); ++it) {
	    size_t index = *it;
		int i = 0;
	    if (index >= smallNumbers.size()) {
	        continue;
	    }
	    std::pair<void *, void *>* toInsert = smallNumbers[index];
	    size_t left = 0;
	    size_t right = result.size();
	    while (left < right) {
	        size_t mid = left + (right - left) / 2;
	        if (dataOfPairVector(result.begin() + mid) < dataOfPairVector(smallNumbers.begin() + index)) {
	            left = mid + 1;
	        } else {
	            right = mid;
	        }
			i++;
	    }
		// std::cout << "nombre de comparaison pour cette insertion = " << i << std::endl;
	    result.insert(result.begin() + left, toInsert);
	}
    return result;
}


void	PmergeMe::setBeforeVec() {
	_beforeVec = getCurrentTimeInMilliseconds();
}

void	PmergeMe::setAfterVec() {
	_afterVec = getCurrentTimeInMilliseconds();
}

void	PmergeMe::printTimeVec() {
	std::cout << "Time to process a range of " << _pairVec.size() << " elements with std::vector : " << _afterVec - _beforeVec << "us" << std::endl;
}