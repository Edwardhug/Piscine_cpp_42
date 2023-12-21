#include <iostream>
#include "../includes/PhoneBook.hpp"

using namespace std;

int	main(void) {
	string	Righted;
	PhoneBook Book;

	Righted = "first";
	while (Righted != "EXIT"){
		cout << "> ";
		getline(cin, Righted);
		if (Righted == "ADD")
			Book.add_contact();
	}


}