#include <string>
#include <iostream>



int	main() {
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	std::cout << "Memory address of the string : " << &str << std::endl;
	std::cout << "Memory address of the stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory address of the stringREF : " << &stringREF << std::endl;

	std::cout << "String value : " << str << std::endl;
	std::cout << "value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF : " << stringREF << std::endl;
}