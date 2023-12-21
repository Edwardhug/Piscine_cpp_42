#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include "Contact.hpp"

class	PhoneBook {
	public :

	void add_contact(Contact Contact);
	// void get_contact(Contact Contact);

	private :

	Contact m_contact[8];
	int		m_number_of_contact;
	int		m_next_to_change;
};

#endif