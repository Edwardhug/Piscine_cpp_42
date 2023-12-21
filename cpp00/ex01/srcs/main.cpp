#include <iostream>
#include "../includes/PhoneBook.hpp"

using namespace std;

int	main(void) {
	string	Righted;
	PhoneBook Book;

	Righted = "first";
	while (Righted != "EXIT"){
		cout << "What do you want to do with your phonebook ?" << endl;
		cout << "To add a new contact, type ADD" << endl;
		cout << "To get information about your contacts, type SEARCH" << endl;
		cout << "To close it, type EXIT" << endl << "> ";
		getline(cin, Righted);
		if (Righted == "ADD")
			Book.
	}


}