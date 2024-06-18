#include "../includes/RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: Wrong number of arg." << std::endl;
		return 1;
	}
	Rpn polish;
	polish.polishNote(av[1]);
	if (polish.getStack().empty() == true)
		std::cout << "Error: Wrong arg." << std::endl;
	else
		std::cout << "Result = " << polish.getStack().top() << std::endl;
}