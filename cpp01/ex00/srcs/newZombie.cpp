#include "../includes/Zombie.h"
#include <cstdlib>



Zombie	*newZombie(std::string newname) {
	return new Zombie(newname);		// allocation dynamique
}
