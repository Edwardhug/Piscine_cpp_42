#include "../includes/Zombie.h"
#include <cstdlib>

using namespace std;

Zombie	*newZombie(string newname) {
	return new Zombie(newname);		// need better comprehension of this, maybe it will come later
}
