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

	if (this->_vec.size() < 2)
		throw (std::exception());
	else {
		int smallest = _vec.at(0);
		tmp = 0;
		for (long unsigned int i = 0; i < _vec.size(); i++) {
			if (smallest > _vec.at(i)) {
				smallest = _vec.at(i);
				tmp = i;
			}
		}
		int	second;
		long unsigned int j;
		if (tmp == 0) {
			second = _vec.at(1);
			j = 1;
		}
		else {
			second = _vec.at(0);
			j = 0;
		}
		while (j < _vec.size()) {
			if (second > _vec.at(j) && j != tmp) {
				second = _vec.at(j);
			}
			j++;
		}
		if (second != smallest)
			second--;
		return (second - smallest);
	}
}

unsigned int Span::longestSpan() const {
	int smallest;
	int longest;
	if (this->_vec.size() < 2)
		throw (std::exception());
	else {
		smallest = _vec.at(0);
		
		longest = _vec.at(0);
		for (long unsigned int i = 0; i < _vec.size(); i++) {
			if (smallest > _vec.at(i))
				smallest = _vec.at(i);
			if (longest < _vec.at(i))
				longest = _vec.at(i);
		}
		return (longest - smallest);
	}
}

void	Span::addNumbers(std::vector<int> range) {
	long unsigned int global_size;

	global_size = range.size() + _vec.size();
	if (global_size > _n)
		throw (std::exception());
	else {
		std::vector<int>::iterator range_begin = range.begin();
		std::vector<int>::iterator range_end = range.end();
		_vec.insert(_vec.end(), range_begin, range_end);
	}
}