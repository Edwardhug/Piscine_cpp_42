#include "../includes/Zombie.h"

using namespace std;

void	randomChump(string name) {
	Zombie	Zom(name);
	Zom.announce();
}