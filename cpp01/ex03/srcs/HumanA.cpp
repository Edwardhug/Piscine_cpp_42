#include "../includes/HumanA.hpp"
#include <iostream>



HumanA::HumanA(std::string new_name, Weapon &new_Weapon) : Weapon_player(new_Weapon) {
	name = new_name;
}

HumanA::~HumanA() {

}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << Weapon_player.getType() << std::endl;
}
