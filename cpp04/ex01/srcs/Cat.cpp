#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Simple Cat constructor called" << std::endl;
	this->_brain = new Brain;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat named " << type << " constructor called" << std::endl;
	this->_brain = new Brain;
}

Cat::~Cat() {
	std::cout << "Cat named " << this->_type << " destructor called" << std::endl;
	delete(this->_brain);
}

Cat::Cat(Cat const &copy) : Animal(copy) {
	std::cout << "Cat named " << copy._type << " copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy) {
	this->_type = copy._type;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}