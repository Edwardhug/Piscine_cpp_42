#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	public :

	Dog();
	Dog(std::string type);
	~Dog();
	Dog(Dog const &copy);
	Dog &operator=(Dog const &copy);
	void makeSound() const;
	void printThought(int i) const;

	private :

	Brain *_brain;
};

#endif