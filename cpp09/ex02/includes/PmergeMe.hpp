#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <exception>
# include <utility>

class	PmergeMe {
	private :

	std::vector<unsigned int> _vec;
	std::deque<unsigned int> _deq;
	std::vector<std::pair<unsigned int, unsigned int> *> _pairVec;
	std::deque<std::pair<void *, void *> *> _pairDeq;
	int	_deep;

	public :

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);

	void	fillContainers(char **av);
	void	printVec();
	void	printDeq();
	void	fillPair();
	// void	printPair();
	void	sortVecFirst();

	private :
	unsigned int data_of_pair(void * pairi) const;
	std::vector<std::pair<void *, void *>*>	recursivSortVec(std::vector<std::pair<void *, void *> *> &toSort);

	void compare_and_swap(std::vector<std::pair<void *, void *> *>::iterator it);
	std::vector<std::pair<void *, void *> *> pairageVec(std::vector<std::pair<void *, void *> *> &toSort);
	std::vector<std::pair<void *, void *>*>	depairageVec(std::vector<std::pair<void *, void *> *> &toDep);
	std::vector<void *> getOnlyBig(std::vector<std::pair<void *, void *> *> &vec);
	std::vector<void *> getOnlySmall(std::vector<std::pair<void *, void *> *> &vec);
	void binaryInsert(std::vector<void*>& arr, void* value);
	std::vector<void*> mergeInsertion(std::vector<void*>& larger, std::vector<void*>& smaller);

};

#endif