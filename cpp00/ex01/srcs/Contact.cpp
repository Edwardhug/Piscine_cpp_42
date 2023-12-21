# include <string>
# include <iostream>
# include "../includes/Contact.hpp"

using namespace std;

Contact::Contact(){
	m_first_name = "";
	m_last_name = "";
	m_nick_name = "";
	m_phone = "";
	m_secret = "";
}

void	Contact::change_first_name(string new_name){
	m_first_name = new_name;
}

void	Contact::change_last_name(string new_last_name){
	m_first_name = new_last_name;
}

void	Contact::change_nick_name(string new_nick_name){
	m_first_name = new_nick_name;
}

void	Contact::change_phone(string num){
	m_phone = num;
}

void	Contact::change_secret(string secret){
	m_secret = secret;;
}