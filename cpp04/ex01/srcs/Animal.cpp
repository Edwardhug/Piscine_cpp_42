#include "../includes/Animal.hpp"

Animal::Animal() : _type("animal") {
	std::cout << "Animal without type constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal " << type << " constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal " << this->_type << " destructor called" << std::endl;
}

Animal::Animal(Animal const &copy) {
	*this = copy;
}

Animal &Animal::operator=(Animal const &copy) {
	this->_type = copy._type;
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << this->_type << " the unknow animal makes a sound" << std::endl;
}

std::string	Animal::getType() const {
	return (this->_type);
}