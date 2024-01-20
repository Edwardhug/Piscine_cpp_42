#include "../includes/HumanB.hpp"
#include <iostream>



HumanB::HumanB(std::string new_name) {
	name = new_name;
	Weapon_player = NULL;
}

HumanB::~HumanB() {

}

void	HumanB::attack() {
	std::cout << name << " attacks with their ";
	if (Weapon_player != NULL)
		std::cout << Weapon_player->getType() << std::endl;
	else
		std::cout << "fists" << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon) {
	Weapon_player = &new_weapon;
}
