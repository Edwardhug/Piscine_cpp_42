#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	public :

	Animal();
	Animal(std::string type);
	virtual ~Animal();
	Animal(Animal const &copy);
	Animal &operator=(Animal const &copy);
	virtual void makeSound() const = 0;
	std::string getType() const;

	protected :

	std::string	_type;
};

#endif