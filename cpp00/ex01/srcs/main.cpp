#include <iostream>
#include <stdlib.h>
#include "../includes/PhoneBook.hpp"



int	main(void) {
	PhoneBook	Book;
	std::string		Righted;

	Righted = "first";
	while (Righted != "EXIT"){
		std::cout << "> ";
		std::getline(std::cin, Righted);
		if (!std::cin){
			std::cout << "Ctrl + d detected, clean exit" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (Righted == "ADD")
			Book.add_contact();
		if (Righted == "SEARCH"){
			Book.search_contact();
		}
	}
}