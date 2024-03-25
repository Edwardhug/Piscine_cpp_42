#include "../includes/ScavTrap.hpp"

int main()
{
    std::cout << "Clap test" << std::endl << std::endl;

    ClapTrap Clap("clap");
	Clap.attack("the target");
	Clap.takeDamage(5);
	Clap.beRepaired(5);

	std::cout << std::endl << "Scav test" << std::endl <<std::endl;

	ScavTrap Scav("Scav");
	Scav.attack("the target");
	Scav.takeDamage(5);
	Scav.beRepaired(5);
	Scav.guardGate();

	std::cout << std::endl << "Destructors" << std::endl <<std::endl;
}