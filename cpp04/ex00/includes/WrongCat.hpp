#ifndef WrongCat_HPP
# define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public :

	WrongCat();
	WrongCat(std::string type);
	~WrongCat();
	WrongCat(WrongCat const &copy);
	WrongCat &operator=(WrongCat const &copy);
	void makeSound() const;
};

#endif