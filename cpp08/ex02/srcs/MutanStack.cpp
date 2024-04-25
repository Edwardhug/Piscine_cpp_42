#include "../includes/MutanStack.hpp"

template <typename T>
MutanStack<T>::MutanStack() : std::stack() {}

template <typename T>
MutanStack<T>::~MutanStack() {}

template <typename T>
MutanStack<T>::MutanStack(const MutanStack &copy) : std::stack(copy) {}

template <typename T>
MutanStack<T>	&MutanStack<T>::operator=(const MutanStack &copy) {
	std::stack::operator=(copy);
	return (*this);
}

template <typename T>
typename MutanStack<T>::iterator	MutanStack<T>::begin() {
	return (std::stack::c.begin());
}

// template <typename T>
// typename MutanStack<T>::const_iterator	MutanStack<T>::begin() {
// 	return (std::stack::c.begin());
// }