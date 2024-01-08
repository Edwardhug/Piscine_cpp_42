#include "../includes/Zombie.h"

using namespace std;

int	main(void) {
	int	N = 4;
	int i = 0;
	Zombie *benjamin = zombieHorde(N, "Benjamin");

	while (i < N) {
		cout << i + 1 << " ";
		benjamin[i].announce();
		i++;
	}
	delete [] benjamin;
}