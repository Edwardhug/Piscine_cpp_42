#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>

class Span {
	private :

	std::vector<int>	_vec;
	long unsigned int	_n;

	public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &copy);

	void	addNumber(int num);
	int	shortestSpan() const;
	int	longestSpan() const;

	template <typename iterator>
	void	addNumbers(iterator begin, iterator end) {
	long unsigned int global_size;
	size_t rangeSize = 0;
	iterator copy;

	copy = begin;
	while (copy != end) {
		copy++;
		rangeSize++;
	}
	global_size = rangeSize + _vec.size();
	if (global_size > _n)
		throw (std::exception());
	while (begin != end) {
		_vec.push_back(*begin);
		begin++;
	}
}
};

#endif