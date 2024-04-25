#ifndef MUTANSTACK_HPP
# define MUTANSTACK_HPP

# include <stack>

template <typename T>
class MutanStack : public std::stack<T> {
	public :

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutanStack();
	~MutanStack();
	MutanStack(const MutanStack &copy);
	MutanStack<T> &operator=(const MutanStack &copy);

	iterator begin();
	const_iterator begin();
	iterator end();
	const_iterator end();

	//input iterator
	//output iterator pas sur
	//forward iterator
	//random access iterator
};

#endif