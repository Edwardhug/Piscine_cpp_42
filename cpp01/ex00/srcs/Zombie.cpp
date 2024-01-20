#include "../includes/Zombie.hpp"



Zombie::Zombie() {
}

Zombie::Zombie(std::string newname) : name(newname) {
}

Zombie::~Zombie() {
}

void	Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
}
