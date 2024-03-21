#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Scav") {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap " << "Scav" << " constuctor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap " << name << " constuctor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) {
	std::cout << "ScavTrap " << this->_name << " copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copy) {
	ClapTrap::operator=(copy);
	return (*this);
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_energy_points > 0) {
		std::cout << "ScavTrap " << this->_name << ", causing " << this->_attack_damage << " points of damage to " << target << " !" << std::endl;
		this->_energy_points--;
	}
	else
		std::cout << "ScavTrap " << this->_name << "don't have energy !" << std::endl;
}