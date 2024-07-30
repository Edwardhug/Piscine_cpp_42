#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"

void PmergeMe::compare_and_swap(std::vector<std::pair<void *, void *> *>::iterator it) {
	std::pair<void *, void *> *pair = *it;
	unsigned int	first = data_of_pair(&(pair->first));
	unsigned int	second = data_of_pair(&(pair->second));
	if (first < second) {
		swapVector(it);
	}
	// std::cout<< "first = " << first << std::endl;
	// std::cout<< "second = " << second << std::endl;
	// std::cout << "I SWAP BITCHES" << std::endl;
}

std::vector<std::pair<void *, void *> *>	PmergeMe::pairageVec(std::vector<std::pair<void *, void *> *> &toSort) {

	// std::cout << "pairage" << std::endl;

	std::vector<std::pair<void *, void *> *> newVec;
	for (std::vector<std::pair<void *, void *> *>:: iterator it = toSort.begin() ; it != toSort.end() ; it++) {
		void * first = *it;
		it++;
		if (it == toSort.end())
			break ;
		void * second = *it;
		std::pair<void *, void *> *pair = new std::pair<void*, void*>(first, second);
		// std::cout << "pairage value : "  << std::endl;
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

// binaryInsert()

std::vector<void *> PmergeMe::getOnlyBig(std::vector<std::pair<void *, void *> *> &vec) {
	std::vector<void*>	toRet;

	for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); it++) {
		toRet.push_back((*it)->second);
	}
	return toRet;
}

std::vector<void *> PmergeMe::getOnlySmall(std::vector<std::pair<void *, void *> *> &vec) {
	std::vector<void*>	toRet;

	for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); it++) {
		toRet.push_back((*it)->first);
		
	}
	return toRet;
}

std::vector<unsigned int> generateJacobsthalSequence(unsigned int n) {
    std::vector<unsigned int> sequence;
    unsigned int a = 0, b = 1;
    while (b < n) {
        sequence.push_back(b);
        unsigned int next = b + 2 * a;
        a = b;
        b = next;
    }
    return sequence;
}

void PmergeMe::binaryInsert(std::vector<void*>& arr, void* value) {
    int left = 0, right = static_cast<int>(arr.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data_of_pair(arr[mid]) < data_of_pair(value))
            left = mid + 1;
        else
            right = mid - 1;
    }
    arr.insert(arr.begin() + left, value);
}

std::vector<void*> PmergeMe::mergeInsertion(std::vector<void*>& larger, std::vector<void*>& smaller) {
    std::vector<void*> result = larger;  // Start with the sorted larger elements
    
    std::vector<unsigned int> jacobsthal = generateJacobsthalSequence(smaller.size());
    
    unsigned int lastInserted = 1;  // We start from the 2nd element (index 1)
    for (size_t idx = 0; idx < jacobsthal.size(); ++idx) {
        unsigned int j = jacobsthal[idx];
        if (j >= smaller.size()) break;
        
        // Binary insert the element at index j-1
        binaryInsert(result, smaller[j-1]);
        
        // Insert all elements between lastInserted and j-1, from right to left
        for (int i = static_cast<int>(j) - 2; i >= static_cast<int>(lastInserted); --i) {
            binaryInsert(result, smaller[i]);
        }
        
        lastInserted = j;
    }
    
    // Insert any remaining elements
    for (int i = static_cast<int>(smaller.size()) - 1; i >= static_cast<int>(lastInserted); --i) {
        binaryInsert(result, smaller[i]);
    }
    
    return result;
}

std::vector<std::pair<void *, void *>*> PmergeMe::depairageVec(std::vector<std::pair<void *, void *> *> &toDep) {
    std::vector<void*> bigNumber = getOnlyBig(toDep);
    std::vector<void*> smallNumber = getOnlySmall(toDep);
    
    // Perform merge insertion
    std::vector<void*> sortedElements = mergeInsertion(bigNumber, smallNumber);
    
    // Convert sorted vector<void*> to vector<pair<void*, void*>*>
    std::vector<std::pair<void *, void *>*> afterDep;
    for (size_t i = 0; i < sortedElements.size(); i += 2) {
        void* first = sortedElements[i];
        void* second = (i + 1 < sortedElements.size()) ? sortedElements[i + 1] : NULL;
        
        std::pair<void*, void*>* newPair = new std::pair<void*, void*>(first, second);
        afterDep.push_back(newPair);
    }
    // Clean up the old pairs
    for (size_t i = 0; i < toDep.size(); ++i) {
        delete toDep[i];
    }
    return afterDep;
}

std::vector<std::pair<void *, void *>*>	PmergeMe::recursivSortVec(std::vector<std::pair<void *, void *> *> &toSort) {
	_deep++;
	// std::cout << "we need to go deeper : " << _deep << std::endl;
	std::vector<std::pair<void *, void *> *> newVec = pairageVec(toSort);
	std::pair<void *, void *> *dernier_elem = last(toSort); // renvoi un last si la len est impaire sinon renvoi null
	if (newVec.size() == 1)
		return newVec;
	if (dernier_elem)
		std::cout << "dernier element" << data_of_pair(static_cast<std::pair<void *, void*>*>(dernier_elem)) << std::endl;
	std::vector<std::pair<void *, void *>*> return_vec = recursivSortVec(newVec);
	(void)dernier_elem;
	if (dernier_elem) {
		std::cout << " y a un ptn de dernier element";
	} else {
		// std:: cout << "NON";
	}
	// std :: cout << std::endl;

	return_vec = depairageVec(return_vec);

	_deep--;

	return return_vec;

}
// vector main =[] 
// vecytor avant = [super pair de dingue]

// main = avant.first 
// pend = avant.second

// pend -> main

// pend[1] comparer avec le 1er eleme 2^n -1
// ou n est le nombre de sequence d'insertion ( le rang de la suite de jacobshtal )
// pend[3] comparer avec les 3 premiesr elem
// pend[2]
// pend[5] comparer avec les 7 premiers
// pend[4]
// pend[11] comparer avec les 15 premiers


void	PmergeMe::sortVecFirst() {
	std::vector<std::pair<void *, void *> *>	toSort;
	// std::cout << "sort" << std::endl;
	toSort = serializerVector(_pairVec);
	recursivSortVec(toSort);
}

// 1         1            3         5         11         21  
// 1                2           2       6           10        
//                                  2u(n-2) + u(n -1)  = u(n)