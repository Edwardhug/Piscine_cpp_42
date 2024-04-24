#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	iter(T *array, int length, void	(*f)(T&)) {
	for (int i = 0; i < length && array[i]; i++)
		f(array[i]);
	
}

template<typename T>
void	test_print_function(T &str) {
	std::cout << str;
}


#endif