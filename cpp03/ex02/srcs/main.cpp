#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

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

        std::cout << std::endl << "Frag test" << std::endl <<std::endl;

        FragTrap Frag("Frag");
        Frag.attack("the target");
        Frag.takeDamage(5);
        Frag.beRepaired(5);
        Frag.highFivesGuys();

        std::cout << std::endl << "Destructors" << std::endl <<std::endl;
}