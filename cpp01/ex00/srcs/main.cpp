#include "../includes/Zombie.h"

int	main(void) {
	Zombie *Zom;

	Zom = newZombie("Joe");
	randomChump("Benjamin");
	Zom->announce();
	return (0);
}
