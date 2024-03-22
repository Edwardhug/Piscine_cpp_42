# include "../includes/Brain.hpp"
# include <iostream>

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "Eat";
		i++;
		_ideas[i] = "Sleep";
	}
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

void	Brain::printIdea(int i) const {
	if (i < 100 && i >= 0)
		std::cout << this->_ideas[i];
	else
		std::cout << "I did'nt thought that far !" << std::endl;
}