# include <string>
# include <iostream>
# include "../includes/Contact.hpp"
# include <iomanip>

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
	m_last_name = new_last_name;
}

void	Contact::change_nick_name(string new_nick_name){
	m_nick_name = new_nick_name;
}

void	Contact::change_phone(string num){
	m_phone = num;
}

void	Contact::change_secret(string secret){
	m_secret = secret;;
}

string	Contact::trunc_string(string name){
	string	small;

	if (name.size() <= 10)
		return (name);
	small = name.substr(0, 9);
	small = small + ".";
	return (small);
}

void	Contact::get_contact(){
	cout << "|" << setw(10) << right << trunc_string(m_first_name);
	cout << "|" << setw(10) << right << trunc_string(m_last_name);
	cout << "|" << setw(10) << right << trunc_string(m_nick_name) << "|" << endl;
	cout << "├──────────┼──────────┼──────────┼──────────┤" << endl;
}

void	Contact::print_info(){
	cout << "First name : " << m_first_name << endl;
	cout << "Last name : " << m_last_name << endl;
	cout << "Nick name : " << m_nick_name << endl;
	cout << "Phone number : " << m_phone << endl;
	cout << "Darkest secret : " << m_secret << endl;
}