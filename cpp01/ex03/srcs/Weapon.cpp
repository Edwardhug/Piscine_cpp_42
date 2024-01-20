#include "../includes/Weapon.hpp"



Weapon::Weapon(std::string new_type) {
	type = new_type;
}

Weapon::~Weapon() {

}

string const &Weapon::getType(){
	return (type);
}

void	Weapon::setType(std::string new_type) {
	type = new_type;
}

