#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

template<typename T>
typename T::iterator easyfind(T container, int to_find)
{
	typename T::iterator i;

	i = std::find(container.begin(), container.end(), to_find);
	if (i == container.end())
		throw std::exception();
	std::cout << "int found" << std::endl;
	return (i);
}

#endif
