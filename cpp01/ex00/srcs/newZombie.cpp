#include "../includes/Zombie.h"
#include <cstdlib>

using namespace std;

Zombie	*newZombie(string name) {
	Zombie	*Zom;

	Zom = NULL;
	Zom->set_name(name);
	return (Zom);
}
