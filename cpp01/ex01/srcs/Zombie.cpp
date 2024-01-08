#include "../includes/Zombie.hpp"

using namespace std;

Zombie::Zombie() {
}

Zombie::Zombie(string newname) : name(newname) {
}

Zombie::~Zombie() {

}

void	Zombie::announce(void) {
	cout << name << ": BraiiiiiiinnnzzzZ" << endl; 
}

void	Zombie::change_name(string newname) {
	name = newname;
}