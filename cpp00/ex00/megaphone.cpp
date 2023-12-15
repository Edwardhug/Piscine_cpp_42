#include <iostream>

char	**convert_to_capital(int ac, char **av){
	int	i;
	int	j;

	i = 1;
	while (i < ac) {
		j = 0;
		while (av[i][j]) {
			av[i][j] = toupper(av[i][j]);
			j++;
		}
		i++;
	}
	return (av);
}

int main(int ac, char **av) {
	int	i;

	if (ac == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	av = convert_to_capital(ac, av);
	while (i < ac - 1) {
		std::cout << av[i] << " ";
		i++;
	}
	std::cout << av[i] << std::endl;
    return (0);
}
