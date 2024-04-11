#include "../includes/easyfind.hpp"

int main()
{
	std::vector<int> vec;
	std::list<int> list;

	for (int i = 1; i < 6; i++) {
		vec.push_back(i);
		list.push_back(i);
	}

	try {
		easyfind(vec, 2);
		easyfind(list, 3);
	}
	catch (std::exception &e){
		std::cerr << "exception catch" << e.what() << std::endl;
	}
	try {
		easyfind(vec, 6);
	}
	catch (std::exception &e){
		std::cerr << "exception catch :" << e.what() << std::endl;
	}
	try {
		easyfind(list, 6);
	}
	catch (std::exception &e){
		std::cerr << "exception catch :" << e.what() << std::endl;
	}
}