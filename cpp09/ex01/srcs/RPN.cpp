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
			std::cout << "Error: Number above 9." << std::endl;
			return ;
		}
	}
	for (int i = 0; av[i] && av[i + 1]; i++) {
		if (av[i] != ' ' && av[i] != '+' && av[i] != '-' && av[i] != '/' && av[i] != '*' && (av[i] < '0' || av[i] > '9')) {
			std::cout << "Error: Bad character." << std::endl;
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
				std::cout << "Error: Not enough number to do the operation." << std::endl;
				return ;
			}
			temp = _stack.top();
			_stack.pop();
			if (av[i] == '+')
				temp = temp + _stack.top();
			else if (av[i] == '-')
				temp = temp - _stack.top();
			else if (av[i] == '*')
				temp = temp * _stack.top();
			else if (av[i] == '/')
				temp = temp / _stack.top();
			_stack.pop();
			_stack.push(temp);
		}
	}
	if (_stack.size() != 1) {
		std::cout << "Error: Too much number at the end." << std::endl;
		while (_stack.size() != 0)
			_stack.pop();
		return ;
	}
	return ;
}

