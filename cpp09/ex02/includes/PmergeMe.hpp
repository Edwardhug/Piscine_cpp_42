#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <exception>

class	PmergeMe {
	private :

	std::vector<unsigned int> _vec;
	std::deque<unsigned int> _deq;

	public :

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);

	void	fillContainers(char **av);
	void	printVec();
	void	printDeq();
};

#endif