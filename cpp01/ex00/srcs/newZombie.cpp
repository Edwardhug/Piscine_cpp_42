#include "../includes/Zombie.h"
#include <cstdlib>

using namespace std;

Zombie	*newZombie(string newname) {
	return new Zombie(newname);		// allocation dynamique
}
