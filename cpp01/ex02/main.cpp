#include <string>
#include <iostream>

using namespace std;

int	main() {
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	cout << "Memory address of the string : " << &str << endl;
	cout << "Memory address of the stringPTR : " << stringPTR << endl;
	cout << "Memory address of the stringPTR : " << &stringREF << endl;

	cout << "String value : " << str << endl;
	cout << "value pointed by stringPTR : " << *stringPTR << endl;
	cout << "value pointed by stringREF : " << stringREF << endl;
}