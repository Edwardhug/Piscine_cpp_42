#include <iostream>
#include <stdlib.h>
#include "../includes/PhoneBook.hpp"



int	main(void) {
	PhoneBook	Book;
	std::string		Righted;
	bool		newline = true;		//usefull to avoid "> >" after the SEARCH

	Righted = "first";
	while (Righted != "EXIT"){
		if (newline == true)
			std::cout << "> ";
		std::getline(std::cin, Righted);
		if (!std::cin){
			std::cout << "EOF find, clean exit" << std::endl;
			exit(EXIT_FAILURE);
		}
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