#include "../includes/Weapon.hpp"

using namespace std;

Weapon::Weapon(string new_type) {
	type = new_type;
}

Weapon::~Weapon() {

}

string const &Weapon::getType(){
	return (type);
}

void	Weapon::setType(string new_type) {
	type = new_type;
}

