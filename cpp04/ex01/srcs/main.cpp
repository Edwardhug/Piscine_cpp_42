#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <iomanip>

int main()
{
        Animal* animals[10];

        for (int i = 0; i < 10; i++)
        {
                if (i >= 5)
                        animals[i] = new Dog();
                else
                        animals[i] = new Cat();
        }
        std::cout << std::endl;
        for (int i = 0; i < 10; i++)
                delete animals[i];
}
