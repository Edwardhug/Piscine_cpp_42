#include "../includes/HumanB.hpp"
#include <iostream>

using namespace std;

HumanB::HumanB(string new_name) {
	name = new_name;
}

HumanB::~HumanB() {

}

void	HumanB::attack() {
	cout << name << " attacks with their " << Weapon_player.getType() << endl;
}

void	HumanB::setWeapon(Weapon new_weapon) {
	Weapon_player = new_weapon;
}
