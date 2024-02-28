#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
	public :

	Brain();
	~Brain();
	Brain(Brain const &copy);
	Brain &operator=(Brain const &copy);

	private :

	std::string _ideas[100];
};

#endif