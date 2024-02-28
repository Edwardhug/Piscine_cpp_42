#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <string>
#include <iostream>

class WrongAnimal {
	public :

	WrongAnimal();
	WrongAnimal(std::string type);
	~WrongAnimal();
	WrongAnimal(WrongAnimal const &copy);
	WrongAnimal &operator=(WrongAnimal const &copy);
	void makeSound() const;
	std::string getType()const ;

	protected :

	std::string	_type;
};

#endif