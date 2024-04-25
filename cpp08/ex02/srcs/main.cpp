#include "../includes/MutantStack.hpp"

int main()
{
	MutantStack<int> test;

	test.push(0);
	test.push(5);
	test.push(15);
	test.push(20);
	test.pop();
	MutantStack<int>::iterator begin = test.begin();
	MutantStack<int>::iterator end = test.end();
	std::cout << "Begin = " << *begin << std::endl;
	std::cout << "End = " << *end << std::endl;
	while (begin != end) {
		std::cout << "value = " << *begin << std::endl;
		begin++; 
	}
}