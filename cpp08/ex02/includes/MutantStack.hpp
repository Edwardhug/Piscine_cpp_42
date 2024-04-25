#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public :

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack &copy) {*this = copy;};
	MutantStack<T> &operator=(const MutantStack &copy) {this->operator=(copy); return(this);};

	iterator begin() {
		return (this->c.begin());
	};
	const_iterator cbegin() const {
		return (this->c.begin());
	};
	reverse_iterator rbegin() {
		return (this->c.rbegin());
	};
	reverse_iterator crbegin() const {
		return (this->c.crbegin());
	};

	iterator end() {
		return (this->c.end());
	};
	const_iterator cend() const {
		return (this->c.cend());
	};
	reverse_iterator rend() {
		return (this->c.rend());
	};
	reverse_iterator crend() const {
		return (this->c.crend());
	};
};

#endif