#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(10) {
	std::cout << "ClapTrap " << name << " constuctor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy) {
	std::cout << "ClapTrap assignement operator called" << std::endl;
	this->_name = copy._name;
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._hit_points;
	this->_attack_damage = copy._attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_energy_points > 0) {
		std::cout << "ClapTrap " << this->_name << ", causing " << this->_attack_damage << " points of damage to " << target << " !" << std::endl;
		this->_energy_points--;
	}
	else
		std::cout << "ClapTrap " << this->_name << "don't have energy !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points <= (int)amount) {
		this->_hit_points = 0;
		std::cout << "ClapTrap " << this->_name << " died !" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_name << " take " << amount << " damages !" << std::endl;
		this->_hit_points -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points > 0) {
		std::cout << "ClapTrap " << this->_name <<  " is repaired of " << amount << " hit points !" << std::endl;
		this->_energy_points--;
		this->_hit_points += amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << "don't have energy !" << std::endl;
}