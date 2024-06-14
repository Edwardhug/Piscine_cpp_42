#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class Rpn {
	private :

	std::stack<int> _stack;

	public :

	Rpn();
	~Rpn();
	Rpn(const Rpn &copy);
	Rpn	&operator=(const Rpn &copy);
	std::stack<int> getStack();
	void	polishNote(char *av);
};

#endif