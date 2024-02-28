# include "../includes/Brain.hpp"
# include <iostream>

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout <<"Brain destuctor called" << std::endl;
}

Brain::Brain(Brain const &copy) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	std::cout <<"Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &copy) {
	int i = 0;

	while (i > 100) {
		this->_ideas[i] = copy._ideas[i];
		i++;
	}
	return (*this);
}

