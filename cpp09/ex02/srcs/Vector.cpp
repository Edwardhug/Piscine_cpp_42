#include "../includes/PmergeMe.hpp"
#include "../includes/lib.hpp"

void PmergeMe::compare_and_swap(std::vector<std::pair<void *, void *> *>::iterator it) {
	std::pair<void *, void *> *pair = *it;
	unsigned int	first = data_of_pair(&(pair->first));
	unsigned int	second = data_of_pair(&(pair->second));
	// std::cout << "first = " << first << std::endl;
	// std::cout << "second = " << second << std::endl;
	if (first < second) {
		swapVector(it);
	}
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
    std::vector<void*> toRet;
    for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); ++it) {
        toRet.push_back((*it)->first);
    }
    return toRet;
}

std::vector<void *> PmergeMe::getOnlySmall(std::vector<std::pair<void *, void *> *> &vec) {
    std::vector<void*> toRet;
    for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); ++it) {
        if ((*it)->second != NULL) {
            toRet.push_back((*it)->second);
        }
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

void PmergeMe::binaryInsert(std::vector<std::pair<void*, void*>*>& arr, void* value) {
    int left = 0, right = static_cast<int>(arr.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data_of_pair(arr[mid]->first) < data_of_pair(value))
            left = mid + 1;
        else
            right = mid - 1;
    }
    std::vector<std::pair<void*, void*>*>::iterator it = arr.begin() + left;
    arr.insert(it, new std::pair<void*, void*>(value, NULL));
}

std::vector<std::pair<void *, void *>*> PmergeMe::mergeInsertion(std::vector<void*>& larger, std::vector<void*>& smaller) {
    std::vector<std::pair<void *, void *>*> result;
    result.reserve(larger.size() + smaller.size());

    // Insérer d'abord tous les éléments de larger
    for (std::vector<void*>::size_type i = 0; i < larger.size(); ++i) {
        result.push_back(new std::pair<void*, void*>(larger[i], NULL));
    }
	// std::cout << "result = ";
	// print_vec_pair(result, _deep + 1);
	// std::cout << std::endl;

    std::vector<unsigned int> jacobsthal = generateJacobsthalSequence(smaller.size());
    
    unsigned int lastInserted = 1;  // Commencer à 1 car le premier élément est déjà "inséré"
    for (std::vector<unsigned int>::size_type idx = 0; idx < jacobsthal.size(); ++idx) {
        unsigned int j = jacobsthal[idx];
        if (j >= smaller.size()) break;
        
        // Insérer l'élément à l'index j-1
		if (idx == 0)	// ? tentative de regler le probleme des 5 pairs au lieu des 4
        	binaryInsert(result, smaller[j-1]);
        
        // Insérer tous les éléments entre lastInserted et j-1, de droite à gauche
        for (int i = static_cast<int>(j) - 2; i >= static_cast<int>(lastInserted); --i) {
            binaryInsert(result, smaller[i]);
        }
        
        lastInserted = j;
    }
    
    // Insérer les éléments restants
    for (std::vector<void*>::size_type i = lastInserted; i < smaller.size(); ++i) {
        binaryInsert(result, smaller[i]);
    }
    
    return result;
}

std::vector<std::pair<void *, void *>*> PmergeMe::depairageVec(std::vector<std::pair<void *, void *> *> &toDep) {
    std::vector<void*> bigNumber = getOnlyBig(toDep);
    std::vector<void*> smallNumber = getOnlySmall(toDep);
    
    // Perform merge insertion
    std::vector<std::pair<void *, void *>*> afterDep = mergeInsertion(bigNumber, smallNumber);
    
    // Clean up the old pairs
    for (std::vector<std::pair<void *, void *> *>::size_type i = 0; i < toDep.size(); ++i) {
        delete toDep[i];
    }
    return afterDep;
}

std::vector<std::pair<void *, void *>*>	PmergeMe::recursivSortVec(std::vector<std::pair<void *, void *> *> &toSort) {
	// std::cout << "before pairage" << std::endl;
	// print_vec_pair(toSort);
	_deep++;
	// std::cout << "we need to go deeper : " << _deep << std::endl;
	std::vector<std::pair<void *, void *> *> newVec = pairageVec(toSort);
	// std::cout << "after pairage" << std::endl;
	// print_vec_pair(newVec);
	std::pair<void *, void *> *dernier_elem = last(toSort); // renvoi un last si la len est impaire sinon renvoi null
	if (newVec.size() == 2) {
		_deep--;
		return newVec;
	}
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

	// std::cout << "before depairage" << std::endl;
	// print_vec_pair(return_vec, _deep + 1);
	return_vec = depairageVec(return_vec);
	// std::cout << "after depairage" << std::endl;
	// print_vec_pair(return_vec, _deep + 1);

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
	toSort = recursivSortVec(toSort);
	std::cout << "after depairage" << std::endl;
	print_vec_pair(toSort, _deep + 2);
	// _deep = 2;
	// print_vec_pair(toSort);
}

// 1         1            3         5         11         21  
// 1                2           2       6           10        
//                                  2u(n-2) + u(n -1)  = u(n)