#include "../includes/Zombie.h"
#include <cstdlib>

using namespace std;

Zombie*	zombieHorde(int N, string name) {
	int i = 0;
	Zombie *horde = new Zombie[N];

	while (i < N) {
		horde[i].change_name(name);
		i++;
	}
	return horde;
}
