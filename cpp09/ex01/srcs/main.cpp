#include "../includes/RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error :wrong number of arg." << std::endl;
		return 1;
	}
	Rpn polish;
	polish.polishNote(av[1]);
	if (polish.getStack().empty() == true)
		std::cout << "Error :wrong arg." << std::endl;
}