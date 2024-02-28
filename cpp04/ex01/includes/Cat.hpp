#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public :

	Cat();
	Cat(std::string type);
	~Cat();
	Cat(Cat const &copy);
	Cat &operator=(Cat const &copy);
	void makeSound() const;

	private :

	Brain *_brain;
};

#endif