#include "../includes/BitcoinExchange.hpp"
#include <map>

int main(int ac, char **av) {
	BitcoinExchange exchange;

	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <filename>" << std::endl;
		return 1;
	}
	exchange.fill("data.csv");
	exchange.getPrice(av[1]);
}