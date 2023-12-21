#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"

using namespace std;

PhoneBook::PhoneBook(){
	m_number_of_contact = 0;
	m_next_to_change = 0;
}

void	PhoneBook::add_contact(){
	string	first_name;
	string	last_name;
	string	nick_name;
	string	number;
	string	secret;

	cout << "First name : ";
	getline(cin, first_name);
	cout << "Last name : ";
	getline(cin, last_name);
	cout << "Nick name : ";
	getline(cin, nick_name);
	cout << "Phone number : ";
	getline(cin, number);
	cout << "Darkest secret : ";
	getline(cin, secret);

	m_contact[m_next_to_change].change_first_name(first_name);
	m_contact[m_next_to_change].change_last_name(last_name);
	m_contact[m_next_to_change].change_nick_name(nick_name);
	m_contact[m_next_to_change].change_phone(number);
	m_contact[m_next_to_change].change_secret(secret);
	if (m_number_of_contact < 7)
		m_number_of_contact++;
	if (m_next_to_change != 7)
		m_next_to_change++;
	else
		m_next_to_change = 0;
}