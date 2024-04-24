#include <iostream>
#include <stdlib.h>
#include "../includes/Array.hpp"
#include <time.h>

#define MAX_VAL 750

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    Array<Awesome> test(15);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    try {
        std::cout << "complex test 5 = " << test[5] << std::endl;
        numbers[1] = 42;
        std::cout << "accessor test 1 = " << numbers[1] << std::endl;
        numbers[1] = 43;
        std::cout << "accessor test 2 = " << numbers[1] << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "error during added test " << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
	{
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
		std::cout << "try pass, number = "<< numbers[2] << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}