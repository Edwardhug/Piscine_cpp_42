#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	private :

	std::string name;
	Weapon		&Weapon_player;

	public :

	HumanA(std::string new_name, Weapon &new_Weapon);
	~HumanA();
	void attack();
};

#endif