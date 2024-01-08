#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <iomanip>

class	Zombie {
	private :

	std::string name;

	public :

	Zombie();
	Zombie(std::string newname);
	~Zombie();
	void	change_name(std::string newname);
	void	announce(void);
};

#endif