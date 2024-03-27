#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Simple Dog constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog named " << type << " constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog named " << this->_type << " destructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy) {
	this->_type = copy._type;
	std::cout << "Dog named " << copy._type << " copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy) {
	this->_type = copy._type;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}