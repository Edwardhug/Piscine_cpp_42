#include "../includes/Harl.hpp"

using namespace std;

Harl::Harl() {
	fonction[0] = &Harl::debug;
    fonction[1] = &Harl::info;
    fonction[2] = &Harl::warning;
    fonction[3] = &Harl::error;
}

Harl::~Harl() {
}


void	Harl::debug(void) {
	cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << endl;
}

void	Harl::info(void) {
	cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << endl;
}

void	Harl::warning(void) {
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << endl;
}

void	Harl::error(void) {
	cout << "This is unacceptable, I want to speak to the manager now." << endl;
}

void	Harl::complain(string level) {
	string	list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4) {
		if (level == list[i])
			(this->*fonction[i])();
		i++;
	}
}
