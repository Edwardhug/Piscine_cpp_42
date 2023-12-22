#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include <iostream>
# include "Contact.hpp"

class	PhoneBook {
	public :

	PhoneBook();
	void	add_contact();
	void	search_contact();

	private :

	Contact m_contact[8];
	int		m_number_of_contact;
	int		m_next_to_change;
};

#endif