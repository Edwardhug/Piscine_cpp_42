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

int Span::shortestSpan() const {
	std::vector<int>	sorted;

	if (this->_vec.size() < 2)
		throw (std::exception());
	sorted = _vec;
	std::sort(sorted.begin(), sorted.end());

	int span = sorted.at(1) - sorted.at(0);
	for (unsigned long i = 0; sorted.size() > i && sorted.size() > i + 1; i++) {
		if (span > (sorted.at(i + 1) - sorted.at(i)))
			span = sorted.at(i + 1) - sorted.at(i);
	}
	return (span);
}

int Span::longestSpan() const {
	if (this->_vec.size() < 2)
		throw (std::exception());
	return (*std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end()));
}