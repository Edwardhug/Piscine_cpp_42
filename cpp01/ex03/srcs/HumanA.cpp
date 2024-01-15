#include "../includes/HumanA.hpp"
#include <iostream>

using namespace std;

HumanA::HumanA(string new_name, Weapon &new_Weapon) : Weapon_player(new_Weapon) {
	name = new_name;
}

HumanA::~HumanA() {

}

void	HumanA::attack() {
	cout << name << " attacks with their " << Weapon_player.getType() << endl;
}
