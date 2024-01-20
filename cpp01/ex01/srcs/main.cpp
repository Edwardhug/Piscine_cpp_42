#include "../includes/Zombie.h"



int	main(void) {
	int	N = 4;
	int i = 0;
	Zombie *benjamin = zombieHorde(N, "Benjamin");

	while (i < N) {
		std::cout << i + 1 << " ";
		benjamin[i].announce();
		i++;
	}
	delete [] benjamin;
}