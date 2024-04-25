#include "../includes/BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	*this = copy;
	return *this;
}

void BitcoinExchange::load(const char *filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}
	
}