#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal without type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal " << type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal " << this->_type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) {
	this->_type = copy._type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy) {
	this->_type = copy._type;
	return (*this);
}

void	WrongAnimal::makeSound() const {
	std::cout << this->_type << " the unknow WrongAnimal makes a sound" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (this->_type);
}