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
	for (int i = 0; av[i] && av[i + 1]; i++) {
		if ((av[i] >= '0' && av[i] <= '9') && (av[i + 1] >= '0' && av[i + 1] <= '9')) {
			return ;
		}
	}
	for (int i = 0; av[i] && av[i + 1]; i++) {
		if (av[i] != ' ' && av[i] != '+' && av[i] != '-' && av[i] != '/' && av[i] != '*' && (av[i] < '0' || av[i] > '9')) {
			return ;
		}
	}
	int temp;
	for (int i = 0; av[i] && av[i + 1]; i++) {
		while (av[i] == ' ')
			i++;
		if (av[i] >= '0' && av[i] <= '9')
			_stack.push(av[i] - '0');
		else if (av[i] == '+' || av[i] == '-' || av[i] == '/' || av[i] == '*') {
			if (_stack.size() == 1) {
				_stack.pop();
				return ;
			}
			temp = _stack.top();
			_stack.pop();
			if (av[i] == '+')
				temp = _stack.top() + temp;
			else if (av[i] == '-')
				temp = _stack.top() - temp;
			else if (av[i] == '*')
				temp = _stack.top() * temp;
			else if (av[i] == '/')
				temp = _stack.top() / temp;
			_stack.pop();
			_stack.push(temp);
		}
	}
	if (_stack.size() != 1) {
		while (_stack.size() != 0)
			_stack.pop();
		return ;
	}
	return ;
}

