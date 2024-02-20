#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Constuctor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy) {
	std::cout << "Assignement operator called" << std::endl;
	this->_name = copy._name;
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._hit_points;
	this->_attack_damage = copy._attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << this->_name << ", causing " << this->_attack_damage << " points of damage !" << std::endl;
}