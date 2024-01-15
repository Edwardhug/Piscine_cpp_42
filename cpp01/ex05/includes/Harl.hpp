#ifndef HARL_HPP
# define HARL_HPP

# include <string.h>
# include <iostream>

class Harl {
	private :

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void	(Harl::*fonction[4])();

	public :

	Harl();
	~Harl();
	void	complain(std::string level);
};

#endif