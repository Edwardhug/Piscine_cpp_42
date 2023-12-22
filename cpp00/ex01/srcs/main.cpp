#include <iostream>
#include "../includes/PhoneBook.hpp"

using namespace std;

int	main(void) {
	PhoneBook	Book;
	string		Righted;
	bool		newline = true;		//usefull to avoid "> >" after the SEARCH

	Righted = "first";
	while (Righted != "EXIT"){
		if (newline == true)
			cout << "> ";
		getline(cin, Righted);
		if (Righted == "ADD")
			Book.add_contact();
		if (Righted == "SEARCH"){
			Book.search_contact();
			newline = false;
		}
		else
			newline = true;
	}
}