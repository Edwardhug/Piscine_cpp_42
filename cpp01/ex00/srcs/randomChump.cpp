#include "../includes/Zombie.h"

using namespace std;

void	randomChump(string name) {
	Zombie	Zom;

	Zom.set_name(name);
	Zom.announce();
}