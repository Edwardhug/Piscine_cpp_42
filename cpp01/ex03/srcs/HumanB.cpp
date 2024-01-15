#include "../includes/HumanB.hpp"
#include <iostream>

using namespace std;

HumanB::HumanB(string new_name) {
	name = new_name;
	Weapon_player = NULL;
}

HumanB::~HumanB() {

}

void	HumanB::attack() {
	cout << name << " attacks with their ";
	if (Weapon_player != NULL)
		cout << Weapon_player->getType() << endl;
	else
		cout << "fists" << endl;
}

void	HumanB::setWeapon(Weapon new_weapon) {
	Weapon_player = &new_weapon;
}
