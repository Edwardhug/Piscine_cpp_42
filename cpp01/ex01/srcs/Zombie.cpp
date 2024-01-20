#include "../includes/Zombie.hpp"



Zombie::Zombie() {
}

Zombie::Zombie(std::string newname) : name(newname) {
}

Zombie::~Zombie() {

}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl; 
}

void	Zombie::change_name(std::string newname) {
	name = newname;
}