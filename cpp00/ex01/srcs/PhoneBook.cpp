#include <string>
#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdlib.h>




PhoneBook::PhoneBook(){
	m_number_of_contact = 0;
	m_next_to_change = 0;
}

void	PhoneBook::add_contact(){
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	number;
	std::string	secret;

	std::cout << "First name : ";
	getline(std::cin, first_name);
	if (!std::cin){
		std::cout << "Ctrl + d detected, clean exit" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Last name : ";
	getline(std::cin, last_name);
	if (!std::cin){
		std::cout << "Ctrl + d detected, clean exit" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Nick name : ";
	getline(std::cin, nick_name);
	if (!std::cin){
		std::cout << "Ctrl + d detected, clean exit" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Phone number : ";
	getline(std::cin, number);
	if (!std::cin){
		std::cout << "Ctrl + d detected, clean exit" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Darkest secret : ";
	getline(std::cin, secret);
	if (!std::cin){
		std::cout << "Ctrl + d detected, clean exit" << std::endl;
		exit(EXIT_FAILURE);
	}
	m_contact[m_next_to_change].change_first_name(first_name);
	m_contact[m_next_to_change].change_last_name(last_name);
	m_contact[m_next_to_change].change_nick_name(nick_name);
	m_contact[m_next_to_change].change_phone(number);
	m_contact[m_next_to_change].change_secret(secret);
	if (m_number_of_contact < 8)
		m_number_of_contact++;
	if (m_next_to_change != 7)
		m_next_to_change++;
	else
		m_next_to_change = 0;
}

bool	is_numeric(std::string index) {
	for (int i = 0; index[i]; i++) {
		if (index[i] < '0' || index[i] > '9')
			return (false);
	}
	return true;
}

void	PhoneBook::search_contact(){
	int			i;
	std::string index;

	i = 0;
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│" << std::setw(10) << std::right << "index";
	std::cout << "│" << std::setw(10) << std::right << "first name";
	std::cout << "│" << std::setw(10) << std::right << "last name";
	std::cout << "│" << std::setw(10) << std::right << "nickname" << "│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	while (i < m_number_of_contact)
	{
		std::cout << "|" << std::setw(10) << std::right << i + 1;
		m_contact[i].get_contact();
		i++;
	}
	if (m_number_of_contact == 0)
		return ;
	while (1){
		std::cout << "Index : " ;
		getline(std::cin, index);
		if (!std::cin){
			std::cout << "Ctrl + d detected, clean exit" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (is_numeric(index) == false || atoi(index.c_str()) > m_number_of_contact || atoi(index.c_str()) < 1) {
			std::cout << "Waiting for a valid index" << std::endl;
		}
		else {
			m_contact[atoi(index.c_str()) - 1].print_info();
			return ;
		}
	}
}