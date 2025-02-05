# include "../includes/lib.hpp"
# include "../includes/PmergeMe.hpp"
# include <sys/time.h>
# include <ctime>
#include <climits>

void *atoui(char *str) {
	unsigned int ret;
	unsigned long int temp;
	ret = 0;
	int i = 0;
	unsigned long int	j = 1;

	while (str[i] && str[i + 1]) 
		i++;
	while (i >= 0 && str[i] != '+') {
		temp = ret + (str[i] - '0') * j;
		ret += (str[i] - '0') * j;
		if ((long int)temp != ret) {
			throw (std::exception());
		}
		j *= 10;
		i--;
	}
	void *addr = new unsigned long int(ret);
	return (addr);
}

void	PmergeMe::printResult(std::vector<std::pair<void *, void *> *> vec) {
	_deep = 1;
	for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << dataOfPairVector(it) << " ";
	}
	std::cout << std::endl;
}

long long	getCurrentTimeInMilliseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}