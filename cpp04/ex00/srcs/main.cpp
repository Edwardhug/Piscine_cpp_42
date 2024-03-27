#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
        Animal g_animal;
        const Animal the_cat("The_cat");
        const Animal the_dog("The_dog");
        const WrongAnimal w_animal("W_animal");
        const WrongCat w_cat("W_cat");

        std::cout << std::endl << the_cat.getType() << " " << std::endl;
        std::cout << the_dog.getType() << " " << std::endl;
        std::cout << w_animal.getType() << " " << std::endl;
        std::cout << w_cat.getType() << " " << std::endl << std::endl;
        the_cat.makeSound();
        the_dog.makeSound();
        g_animal.makeSound();
        std::cout << std::endl;
        w_animal.makeSound();
        w_cat.makeSound();
        std::cout << std::endl;
}