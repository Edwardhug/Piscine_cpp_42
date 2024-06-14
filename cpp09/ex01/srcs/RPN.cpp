#include "../includes/RPN.hpp"

Rpn::Rpn() {}

Rpn::~Rpn() {}

Rpn::Rpn(const Rpn &copy) {
	_stack = copy._stack;
}

Rpn	&Rpn::operator=(const Rpn &copy) {
	_stack = copy._stack;
	return *this;
}

std::stack<int> Rpn::getStack() {
	return _stack;
}

void	Rpn::polishNote(char *av) {
	int i = 0;

	while (av[i]) {
		
	}
}



		if (av[i] != '+' && av[i] != '-' && av[i] != '/' && av[i] != '*' && (av[i] < '0' || av[i] > '9'))
			return (false);