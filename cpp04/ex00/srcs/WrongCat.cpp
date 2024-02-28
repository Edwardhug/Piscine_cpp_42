#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Simple WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "WrongCat named " << type << " constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat named " << this->_type << " destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat named " << copy._type << " copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &copy) {
	this->_type = copy._type;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}