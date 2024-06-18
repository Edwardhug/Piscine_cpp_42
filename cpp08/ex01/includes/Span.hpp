#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

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

	void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif