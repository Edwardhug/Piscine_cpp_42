#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	private :

	std::string type;

	public :
	Weapon(std::string new_type);
	~Weapon();
	std::string const &getType();
	void	setType(std::string new_type);
};

#endif