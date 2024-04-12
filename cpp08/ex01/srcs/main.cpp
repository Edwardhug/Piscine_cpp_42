#include "../includes/Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	Span sp = Span(5);
	try {
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "sp shortest pan " << sp.shortestSpan() << std::endl;
	std::cout << "sp longest pan " << sp.longestSpan() << std::endl;
	sp.addNumber(6546546);
	}
	catch (std::exception &e) {
		std::cerr << "exception catch, too many numbers " << e.what() << std::endl;
	}
	std::cout << std::endl;
	Span small = Span(0);
	try {
		small.addNumber(10);
		std::cout << "small shortest span" <<sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "exception catch, too small vector " << e.what() << std::endl;
	}
	std::cout << std::endl;
	Span big = Span(100000);
	std::vector<int> range;
	for (int i = 0; i < 100000; i++) {
		range.push_back(std::rand());
	}
	try {
		big.addNumbers(range);
		std::cout << "big shortest span " << big.shortestSpan() << std::endl;
		std::cout << "big longest span " <<  big.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "exception catch, error with many numbers " << e.what() << std::endl;
	}

	return 0;
}
