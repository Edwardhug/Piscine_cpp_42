#include "../includes/lib.hpp"
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

void swapVector(std::vector<std::pair<void *, void *> *>::iterator it) {
	void * tmp = (*it)->first;
	(*it)->first = (*it)->second;
	(*it)->second = tmp;
}

std::vector<std::pair<void *, void *>* > serializerVector(std::vector<std::pair<unsigned int, unsigned int>*> toi) {
	std::vector<std::pair< void * , void *> * > return_val;
	for (std::vector< std::pair< unsigned int, unsigned int > *>::iterator it = toi.begin() ; it != toi.end() ; it++) {
		return_val.push_back(reinterpret_cast<std::pair<void *, void *> *>(*it));
	}
	return return_val;
}