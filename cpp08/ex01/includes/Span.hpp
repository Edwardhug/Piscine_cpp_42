#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

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
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;
};

#endif