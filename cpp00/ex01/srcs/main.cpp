#include <iostream>
#include "../includes/PhoneBook.hpp"

using namespace std;

int	main(void) {
	PhoneBook Book;
	string	Righted;

	Righted = "first";
	while (Righted != "EXIT"){
		cout << "> ";
		getline(cin, Righted);
		if (Righted == "ADD")
			Book.add_contact();
		if (Righted == "SEARCH")
			Book.search_contact();
	}


}