#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Frag") {
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 100;
	std::cout << "FragTrap " << "Frag" << " constuctor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 100;
	std::cout << "FragTrap " << name << " constuctor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {
	std::cout << "FragTrap " << this->_name << " copy constructor called" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(FragTrap const &copy) {
	std::cout << "FragTrap " << this->_name << " assignement operator called" << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " is asking to high five everyone !" << std::endl;
}