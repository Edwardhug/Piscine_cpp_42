#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <iomanip>

int main()
{
        Animal* animals[10];

        for (int i = 0; i < 10; i++)
        {
                if (i >= 5) {
                        animals[i] = new Dog();
                        // animals[i] = new Animal();
                }
                else
                        animals[i] = new Cat();
        }
        std::cout << std::endl;

        int num = 1;
	Cat	*Cat_ptr = dynamic_cast<Cat*>(animals[num]);
	if (Cat_ptr)
	{
		std::cout << "printing an idea animals " << num << " thinks ";
		Cat_ptr->printThought(1);
		std::cout << std::endl;
	}

        std::cout << std::endl;
        for (int i = 0; i < 10; i++)
                delete animals[i];
}
