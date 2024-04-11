#include "../includes/Span.hpp"
#include <exception>

Span::Span() : _n(0) {}

Span::Span(unsigned int N) : _n(N) {}

Span::~Span() {}

Span::Span(const Span &copy) {
	this->_n = copy._n;
	this->_vec = copy._vec;
}

Span &Span::operator=(const Span &copy) {
	this->_n = copy._n;
	this->_vec = copy._vec;
	return (*this);
}

void	Span::addNumber(int num) {
	if (this->_vec.size() != _n) {
		this->_vec.push_back(num);
	}
	else
		throw (std::exception());
}

unsigned int Span::shortestSpan() const {
	long unsigned int tmp;

	if (this->_vec.size() == 0 || this->_vec.size() == 1)
		throw (std::exception());
	else {
		int smallest = _vec.at(0);
		tmp = 0;
		for (long unsigned int i = 0; i < _vec.size(); i++) {
			if (smallest < _vec.at(i)) {
				smallest = _vec.at(i);
				tmp = 0;
			}
		}
		int	second;
		if (tmp == 0) {
			second = _vec.at(1);
		}
		else {
			second = _vec.at(0);
		}
		for (long unsigned int i = 0; i < _vec.size(); i++) {
			if (second < _vec.at(i) && i != tmp) {
				second = _vec.at(i);
			}
		}
		return (second - smallest);
	}
}

unsigned int Span::longestSpan() const {
	int smallest;
	int longest;
	if (this->_vec.size() == 0 || this->_vec.size() == 1)
		throw (std::exception());
	else {
		smallest = _vec.at(0);
		longest = _vec.at(0);
		for (long unsigned int i = 0; i < _vec.size(); i++) {
			if (smallest < _vec.at(i))
				smallest = _vec.at(i);
			if (longest > _vec.at(i))
				longest = _vec.at(i);
		}
		return (longest - smallest);
	}
}