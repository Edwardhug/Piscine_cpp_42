#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>

class	Contact {
	public :

	Contact();
	void		change_first_name(std::string new_name);
	void		change_last_name(std::string new_last_name);
	void		change_nick_name(std::string new_nick_name);
	void		change_phone(std::string num);
	void		change_secret(std::string secret);
	void		get_contact();
	std::string	trunc_string(std::string name);
	void		print_info();

	private :

	std::string m_first_name;
	std::string m_last_name;
	std::string m_nick_name;
	std::string m_phone;
	std::string m_secret;
};

#endif