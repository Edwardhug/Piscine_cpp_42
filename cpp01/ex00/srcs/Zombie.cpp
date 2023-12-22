#include "../includes/Zombie.hpp"

using namespace std;

Zombie::Zombie() {
	
}

void	Zombie::announce(void){
	cout << name << ": BraiiiiiiinnnzzzZ" << endl;
}

Zombie	*Zombie::set_name(string newname) {
	Zombie	*Zom;

	Zom->name = newname;
	return (Zom);
}