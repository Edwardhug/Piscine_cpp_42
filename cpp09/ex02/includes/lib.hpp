#ifndef LIB_HPP
# define LIB_HPP

# include "PmergeMe.hpp"

void swapVector(std::vector<std::pair<void *, void *> *>::iterator it);
unsigned int atoui(char *str);
std::vector<std::pair<void *, void *>* > serializerVector(std::vector<std::pair<unsigned int, unsigned int>*> toi);

#endif