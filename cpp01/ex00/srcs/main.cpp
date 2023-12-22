#include "../includes/Zombie.h"

int	main(void) {
	Zombie zombie1("zombie1");
	Zombie *zombie2 = newZombie("zombie2");
	zombie1.announce();
	zombie2->announce();
	randomChump("zombie3");
	delete(zombie2);	// only created zombie with an address
}
