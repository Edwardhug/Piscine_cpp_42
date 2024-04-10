#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>

int main()
{
	Data data(10);

	std::cout << "data of the object " << data.getData() << std::endl;
	std::cout << "before serialize "<< &data << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "after serialize " << raw << std::endl;
	
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "after deserialize " << ptr << std::endl;
	std::cout << "data of the new object " << ptr->getData() << std::endl;
}