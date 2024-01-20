# include <string>
# include <iostream>
# include "../includes/Contact.hpp"
# include <iomanip>



Contact::Contact(){
	m_first_name = "";
	m_last_name = "";
	m_nick_name = "";
	m_phone = "";
	m_secret = "";
}

void	Contact::change_first_name(std::string new_name){
	m_first_name = new_name;
}

void	Contact::change_last_name(std::string new_last_name){
	m_last_name = new_last_name;
}

void	Contact::change_nick_name(std::string new_nick_name){
	m_nick_name = new_nick_name;
}

void	Contact::change_phone(std::string num){
	m_phone = num;
}

void	Contact::change_secret(std::string secret){
	m_secret = secret;;
}

std::string	Contact::trunc_string(std::string name){
	std::string	small;

	if (name.size() <= 10)
		return (name);
	small = name.substr(0, 9);
	small = small + ".";
	return (small);
}

void	Contact::get_contact(){
	std::cout << "|" << std::setw(10) << std::right << trunc_string(m_first_name);
	std::cout << "|" << std::setw(10) << std::right << trunc_string(m_last_name);
	std::cout << "|" << std::setw(10) << std::right << trunc_string(m_nick_name) << "|" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
}

void	Contact::print_info(){
	std::cout << "First name : " << m_first_name << std::endl;
	std::cout << "Last name : " << m_last_name << std::endl;
	std::cout << "Nick name : " << m_nick_name << std::endl;
	std::cout << "Phone number : " << m_phone << std::endl;
	std::cout << "Darkest secret : " << m_secret << std::endl;
}