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
	std::vector<std::pair<void *, void *> > _pairVec;
	std::deque<std::pair<void *, void *> > _pairDeq;

	public :

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);

	void	fillContainers(char **av);
	void	printVec();
	void	printDeq();
	void	sortVec();
	void	fillPair();
	void	printPair();
};

#endif