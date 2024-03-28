#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {
	public :

	Intern();
	~Intern();
	Intern(Intern const &copy);
	Intern &operator=(Intern const &copy);

	AForm	*makeForm(std::string name, std::string target);
};

#endif