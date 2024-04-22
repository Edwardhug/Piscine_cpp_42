#ifndef MUTANSTACK_HPP
# define MUTANSTACK_HPP

# include <stack>

template <typename T>
class MutanStack : public std::stack<T> {
	MutanStack();
	~MutanStack();
	MutanStack(const MutanStack &copy);
	MutanStack &operator(const MutanStack &copy); 
};

#endif