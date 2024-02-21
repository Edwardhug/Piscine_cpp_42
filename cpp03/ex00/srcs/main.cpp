#include "../includes/ClapTrap.hpp"

int	main()
{
	ClapTrap Clap("clap");
	Clap.attack("the target");
	Clap.takeDamage(5);
	Clap.beRepaired(5);
}